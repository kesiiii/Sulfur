#pragma once

#include <Windows.h>
#include <cstdint>
#include <locale>
#include "Enums.h"

class UObject;

class FUObjectItem
{
public:
	UObject* Object;
	DWORD Flags;
	DWORD ClusterIndex;
	DWORD SerialNumber;
	DWORD SerialNumber2;
};

class TUObjectArray
{
public:
	FUObjectItem* Objects[9];
};

class FUObjectArray
{
public:
	TUObjectArray* ObjectArray;
	BYTE _padding_0[0xC];
	DWORD ObjectCount;

	inline int32_t Num()
	{
		return ObjectCount;
	}

	inline void NumChunks(int* start, int* end)
	{
		int cStart = 0, cEnd = 0;

		if (!cEnd)
		{
			while (1)
			{
				if (ObjectArray->Objects[cStart] == 0)
				{
					cStart++;
				}
				else
				{
					break;
				}
			}

			cEnd = cStart;
			while (1)
			{
				if (ObjectArray->Objects[cEnd] == 0)
				{
					break;
				}
				else
				{
					cEnd++;
				}
			}
		}

		*start = cStart;
		*end = cEnd;
	}

	inline UObject* GetByIndex(int32_t Index)
	{
		int cStart = 0, cEnd = 0;
		int chunkIndex = 0, chunkSize = 0xFFFF, chunkPos;
		FUObjectItem* Object;

		NumChunks(&cStart, &cEnd);

		chunkIndex = Index / chunkSize;
		if (chunkSize * chunkIndex != 0 &&
			chunkSize * chunkIndex == Index)
		{
			chunkIndex--;
		}

		chunkPos = cStart + chunkIndex;
		if (chunkPos < cEnd)
		{
			Object = ObjectArray->Objects[chunkPos] + (Index - chunkSize * chunkIndex);

			if (!Object) { return NULL; }

			return Object->Object;
		}

		return nullptr;
	}
};

template<class T>
struct TArray
{
	friend struct FString;

public:
	inline TArray()
	{
		Data = nullptr;
		Count = Max = 0;
	};

	inline int Num() const
	{
		return Count;
	};

	inline T& operator[](int i)
	{
		return Data[i];
	};

	inline const T& operator[](int i) const
	{
		return Data[i];
	};

	inline bool IsValidIndex(int i) const
	{
		return i < Num();
	}

	inline void Add(T InputData)
	{
		Data = (T*)realloc(Data, sizeof(T) * (Count + 1));
		Data[Count++] = InputData;
		Max = Count;
	};

	T* Data;
	int32_t Count;
	int32_t Max;
};

struct FString : private TArray<wchar_t>
{
	inline FString()
	{
	};

	FString(const wchar_t* other)
	{
		Max = Count = *other ? std::wcslen(other) + 1 : 0;

		if (Count)
		{
			Data = const_cast<wchar_t*>(other);
		}
	};

	inline bool IsValid() const
	{
		return Data != nullptr;
	}

	inline const wchar_t* c_str() const
	{
		return Data;
	}

	std::string ToString() const
	{
		auto length = std::wcslen(Data);

		std::string str(length, '\0');

		std::use_facet<std::ctype<wchar_t>>(std::locale()).narrow(Data, Data + length, '?', &str[0]);

		return str;
	}
};

struct FName;

inline void (*FNameToString)(FName* This, FString& OutStr);
inline void (*FreeInternal)(__int64);

struct FName
{
	int32_t ComparisonIndex;
	int32_t Number;

	std::string ToString()
	{
		if (!this)
			return "";

		FString temp;

		FNameToString(this, temp);

		auto wName = std::wstring(temp.c_str());
		auto name = std::string(wName.begin(), wName.end());

		FreeInternal((__int64)temp.c_str());

		auto pos = name.rfind('/');
		if (pos == std::string::npos)
		{
			return name;
		}

		return name.substr(pos + 1);
	}
};

template<class TEnum>
class TEnumAsByte
{
public:
	inline TEnumAsByte()
	{
	}

	inline TEnumAsByte(TEnum _value)
		: value(static_cast<uint8_t>(_value))
	{
	}

	explicit inline TEnumAsByte(int32_t _value)
		: value(static_cast<uint8_t>(_value))
	{
	}

	explicit inline TEnumAsByte(uint8_t _value)
		: value(_value)
	{
	}

	inline operator TEnum() const
	{
		return (TEnum)value;
	}

	inline TEnum GetValue() const
	{
		return (TEnum)value;
	}

private:
	uint8_t value;
};

class UObject
{
public:
	static FUObjectArray* GObjects;
	void** VFT;
	int32_t ObjectFlags;
	int32_t InternalIndex;
	UObject* Class;
	FName Name;
	UObject* Outer;

	std::string GetName()
	{
		return Name.ToString();
	};

	std::string GetFullName()
	{
		std::string name;

		if (Class != nullptr)
		{
			std::string temp;
			for (auto p = Outer; p; p = p->Outer)
			{
				temp = p->GetName() + "." + temp;
			}

			name = Class->GetName();
			name += " ";
			name += temp;
			name += GetName();
		}

		return name;
	};

	template<typename T = UObject>
	static T* FindObject(const std::string& name)
	{
		for (int i = 0; i < GObjects->Num(); ++i)
		{
			auto object = GObjects->GetByIndex(i);

			if (object == nullptr)
			{
				continue;
			}

			if (object->GetFullName().find(name) != std::string::npos)
			{
				return static_cast<T*>(object);
			}
		}
		return nullptr;
	}

	template<typename T = UObject>
	static T* FindObjectFullName(const std::string& name)
	{
		for (int i = 0; i < GObjects->Num(); ++i)
		{
			auto object = GObjects->GetByIndex(i);

			if (object == nullptr)
			{
				continue;
			}

			if (object->GetFullName() == name)
			{
				return static_cast<T*>(object);
			}
		}
		return nullptr;
	}

	static DWORD FindOffset(std::string OffsetToFind)
	{
		UObject* Object = nullptr;

		for (int i = 0; i < GObjects->Num(); i++)
		{
			auto object = GObjects->GetByIndex(i);

			if (object == nullptr)
				continue;

			if (object->GetFullName() == OffsetToFind)
				Object = object;
		}

		if (Object)
		{
			return *(uint32_t*)(__int64(Object) + 0x44);
		}

		return 0;
	}

	bool IsA(UObject* cmp) const
	{
		if (Class == cmp)
			return true;
		return false;
	};
};

FUObjectArray* UObject::GObjects = nullptr;

template<typename Key, typename Value>
class TMap
{
	char UnknownData[0x50];
};

class AActor : public UObject
{
public:
	char pad[0x0300];
};

class UNetConnection;
class UNetDriver;
class UConnection;
class UChildConnection;

struct FUniqueNetIdRepl
{
	unsigned char UnknownData00[0x17];
	TArray<unsigned char> ReplicationBytes;
};

struct FChannelDefinition
{
	FName ChannelName;
	FName ClassName;
	UObject* ChannelClass;
	int StaticChannelIndex;
	bool bTickOnCreate;
	bool bServerOpen;
	bool bClientOpen;
	bool bInitialServer;
	bool bInitialClient;
	unsigned char UnknownData00[0x7];
};

//Class Engine.NetConnection
class UNetConnection : public UObject
{
public:
	TArray<UChildConnection*> Children;
	UNetDriver* Driver;
	UObject* PackageMapClass;
	UObject* PackageMap;
	TArray<class UChannel*> OpenChannels;
	TArray<AActor*> SentTemporaries;
	AActor* ViewTarget;
	AActor* OwningActor;
	int MaxPacket;
	unsigned char InternalAck : 1;
	unsigned char UnknownData00[0xB3];
	FUniqueNetIdRepl PlayerID;
	unsigned char UnknownData01[0x68];
	double LastReceiveTime;
	unsigned char UnknownData02[0x15D8];
	TArray<UChannel*> ChannelsToTick;
	unsigned char UnknownData03[0x148];
};

//Class Engine.NetDriver
class UNetDriver : public UObject
{
public:
	unsigned char UnknownData00[0x8];
	FString NetConnectionClassName;
	FString ReplicationDriverClassName;
	int MaxDownloadSize;
	unsigned char bClampListenServerTickRate : 1;
	unsigned char UnknownData01[0x3];
	int NetServerMaxTickRate;
	int MaxInternetClientRate;
	int MaxClientRate;
	float ServerTravelPause;
	float SpawnPrioritySeconds;
	float RelevantTimeout;
	float KeepAliveTime;
	float InitialConnectTimeout;
	float ConnectionTimeout;
	float TimeoutMultiplierForUnoptimizedBuilds;
	bool bNoTimeouts;
	unsigned char UnknownData02[0x7];
	UNetConnection* ServerConnection;
	TArray<UNetConnection*> ClientConnections;
	unsigned char UnknownData03[0x88];
	UObject* World;
	UObject* WorldPackage;
	unsigned char UnknownData04[0x20];
	UObject* NetConnectionClass;
	UObject* ReplicationDriverClass;
	UObject* RoleProperty;
	UObject* RemoteRoleProperty;
	FName  NetDriverName;
	unsigned char UnknownData05[0x40];
	TArray<FChannelDefinition> ChannelDefinitions;
	TMap<FName, FChannelDefinition> ChannelDefinitionMap;
	TArray<class UChannel*> ActorChannelPool;
	unsigned char UnknownData06[0x8];
	float Time;
	unsigned char UnknownData07[0x49C];
	UObject* ReplicationDriver;
	unsigned char UnknownData08[0x20];
};

//Class Engine.Channel
class UChannel : public UObject
{
public:
	UNetConnection* Connection;
	unsigned char UnknownData00[0x40];
};

//Class Engine.ChildConnection
class UChildConnection : public UNetConnection
{
public:
	UNetConnection* Parent;
};

//Class OnlineSubsystemUtils.OnlineBeacon
class AOnlineBeacon : public AActor
{
public:
	unsigned char UnknownData00[0x8];
	float BeaconConnectionInitialTimeout;
	float BeaconConnectionTimeout;
	UNetDriver* NetDriver;
	EBeaconState BeaconState;
	unsigned char UnknownData01[12];
};

//Class OnlineSubsystemUtils.OnlineBeaconHostObject
class AOnlineBeaconHostObject : public AActor
{
public:
	FString BeaconTypeName;
	UObject* ClientBeaconActorClass;
	TArray<class AOnlineBeaconClient*> ClientActors;
};

//Class OnlineSubsystemUtils.OnlineBeaconClient
class AOnlineBeaconClient : public AOnlineBeacon
{
public:
	AOnlineBeaconHostObject* BeaconOwner;
	UNetConnection* BeaconConnection;
	EBeaconConnectionState ConnectionState;
	unsigned char UnknownData00[0x3F];

	void ClientOnConnected();
};

//Class OnlineSubsystemUtils.IpConnection
class UIpConnection : public UNetConnection
{
public:
	unsigned char UnknownData00[0x60];
};

//Class OnlineSubsystemUtils.IpNetDriver
class UIpNetDriver : public UNetDriver
{
public:
	unsigned char LogPortUnreach : 1;
	unsigned char AllowPlayerPortUnreach : 1;
	unsigned char UnknownData00[0x3];
	uint32_t MaxPortCountToTry;
	unsigned char UnknownData01[0x1C];
	uint32_t ServerDesiredSocketReceiveBufferBytes;
	uint32_t ServerDesiredSocketSendBufferBytes;
	uint32_t ClientDesiredSocketReceiveBufferBytes;
	uint32_t ClientDesiredSocketSendBufferBytes;
	unsigned char UnknownData02[0x14];
};

//Class OnlineSubsystemUtils.OnlineBeaconHost
class AOnlineBeaconHost : public AOnlineBeacon
{
public:
	int ListenPort;
	unsigned char UnknownData00[0x4];
	TArray<AOnlineBeaconClient*> ClientActors;
	int BeaconState;
	unsigned char UnknownData01[0xA0];
};

struct FGuid
{
	int A;
	int B;
	int C;
	int D;
};

struct FRotator
{
	float Pitch;
	float Yaw;
	float Roll;
};

struct FVector
{
	float X;
	float Y;
	float Z;

	auto operator-(FVector A)
	{
		return FVector{ this->X - A.X, this->Y - A.Y, this->Z - A.Z };
	}

	auto operator+(FVector A)
	{
		return FVector{ this->X + A.X, this->Y + A.Y, this->Z + A.Z };
	}

	auto operator==(FVector A)
	{
		return (this->X == A.X && this->Y == A.Y && this->Z == A.Z);
	}

	auto operator!=(FVector A)
	{
		return (this->X != A.X && this->Y != A.Y && this->Z != A.Z);
	}
};

struct FVector2D
{
	float X;
	float Y;

	inline FVector2D()
		: X(0), Y(0)
	{
	}

	inline FVector2D(float x, float y)
		: X(x),
		Y(y)
	{
	}
};

struct FActorSpawnParameters
{
	FActorSpawnParameters() : Name(), Template(nullptr), Owner(nullptr), Instigator(nullptr), OverrideLevel(nullptr),
		SpawnCollisionHandlingOverride(), bRemoteOwned(0), bNoFail(0),
		bDeferConstruction(0),
		bAllowDuringConstructionScript(0),
		NameMode(),
		ObjectFlags()
	{
	}
	;

	FName Name;
	UObject* Template;
	UObject* Owner;
	UObject* Instigator;
	UObject* OverrideLevel;
	ESpawnActorCollisionHandlingMethod SpawnCollisionHandlingOverride;

private:
	uint8_t bRemoteOwned : 1;

public:
	bool IsRemoteOwned() const { return bRemoteOwned; }

	uint8_t bNoFail : 1;
	uint8_t bDeferConstruction : 1;
	uint8_t bAllowDuringConstructionScript : 1;
	ESpawnActorNameMode NameMode;
	EObjectFlags ObjectFlags;
};