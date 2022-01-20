#pragma once

// Fortnite (5.21) SDK

#ifdef _MSC_VER
	#pragma pack(push, 0x8)
#endif

namespace SDK
{
//---------------------------------------------------------------------------
//Enums
//---------------------------------------------------------------------------

// Enum MeshDescription.EComputeNTBsOptions
enum class EComputeNTBsOptions : uint8_t
{
	None                           = 0,
	Normals                        = 1,
	Tangents                       = 2,
	WeightedNTBs                   = 3,
	EComputeNTBsOptions_MAX        = 4
};



//---------------------------------------------------------------------------
//Script Structs
//---------------------------------------------------------------------------

// ScriptStruct MeshDescription.ElementID
// 0x0004
struct FElementID
{
	int                                                IDValue;                                                  // 0x0000(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct MeshDescription.PolygonGroupID
// 0x0000 (0x0004 - 0x0004)
struct FPolygonGroupID : public FElementID
{

};

// ScriptStruct MeshDescription.PolygonID
// 0x0000 (0x0004 - 0x0004)
struct FPolygonID : public FElementID
{

};

// ScriptStruct MeshDescription.VertexID
// 0x0000 (0x0004 - 0x0004)
struct FVertexID : public FElementID
{

};

// ScriptStruct MeshDescription.EdgeID
// 0x0000 (0x0004 - 0x0004)
struct FEdgeID : public FElementID
{

};

// ScriptStruct MeshDescription.VertexInstanceID
// 0x0000 (0x0004 - 0x0004)
struct FVertexInstanceID : public FElementID
{

};

// ScriptStruct MeshDescription.MeshPolygonGroup
// 0x0010
struct FMeshPolygonGroup
{
	unsigned char                                      UnknownData00[0x10];                                      // 0x0000(0x0010) MISSED OFFSET
};

// ScriptStruct MeshDescription.MeshPolygonContour
// 0x0010
struct FMeshPolygonContour
{
	TArray<struct FVertexInstanceID>                   VertexInstanceIDs;                                        // 0x0000(0x0010) (ZeroConstructor)
};

// ScriptStruct MeshDescription.MeshTriangle
// 0x000C
struct FMeshTriangle
{
	struct FVertexInstanceID                           VertexInstanceID0;                                        // 0x0000(0x0004) (BlueprintVisible)
	struct FVertexInstanceID                           VertexInstanceID1;                                        // 0x0004(0x0004) (BlueprintVisible)
	struct FVertexInstanceID                           VertexInstanceID2;                                        // 0x0008(0x0004) (BlueprintVisible)
};

// ScriptStruct MeshDescription.MeshPolygon
// 0x0038
struct FMeshPolygon
{
	struct FMeshPolygonContour                         PerimeterContour;                                         // 0x0000(0x0010)
	TArray<struct FMeshPolygonContour>                 HoleContours;                                             // 0x0010(0x0010) (ZeroConstructor)
	TArray<struct FMeshTriangle>                       Triangles;                                                // 0x0020(0x0010) (ZeroConstructor)
	struct FPolygonGroupID                             PolygonGroupID;                                           // 0x0030(0x0004)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0034(0x0004) MISSED OFFSET
};

// ScriptStruct MeshDescription.MeshEdge
// 0x0018
struct FMeshEdge
{
	struct FVertexID                                   VertexIDs[0x2];                                           // 0x0000(0x0004)
	TArray<struct FPolygonID>                          ConnectedPolygons;                                        // 0x0008(0x0010) (ZeroConstructor)
};

// ScriptStruct MeshDescription.MeshVertexInstance
// 0x0018
struct FMeshVertexInstance
{
	struct FVertexID                                   VertexID;                                                 // 0x0000(0x0004)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0004(0x0004) MISSED OFFSET
	TArray<struct FPolygonID>                          ConnectedPolygons;                                        // 0x0008(0x0010) (ZeroConstructor)
};

// ScriptStruct MeshDescription.MeshVertex
// 0x0020
struct FMeshVertex
{
	TArray<struct FVertexInstanceID>                   VertexInstanceIDs;                                        // 0x0000(0x0010) (ZeroConstructor)
	TArray<struct FEdgeID>                             ConnectedEdgeIDs;                                         // 0x0010(0x0010) (ZeroConstructor)
};

}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
