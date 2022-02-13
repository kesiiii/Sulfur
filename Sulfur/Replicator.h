#pragma once

class Replicator
{
private:
	Beacon* BeaconHost;

public:
	Replicator(Beacon* InBeaconHost)
	{
		BeaconHost = InBeaconHost;
	}
};

namespace NetDriver
{
}