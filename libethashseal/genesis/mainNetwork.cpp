// Aleth: Ethereum C++ client, tools and libraries.
// Copyright 2015-2019 Aleth Authors.
// Licensed under the GNU General Public License, Version 3.

#include "../GenesisInfo.h"

static dev::h256 const c_genesisStateRootMainNetwork("d7f8974fb5ac78d9ac099b9ad5018bedc2ce0a72dad1827a1709da30580f0544");
static std::string const c_genesisInfoMainNetwork = std::string() +
                                                    R"E(
{
  "sealEngine": "Ethash",
	"params": {
		"accountStartNonce": "0x00",
		"homesteadForkBlock": "0x118c30",
		"daoHardforkBlock": "0x0",
		"EIP150ForkBlock": "0x259518",
		"EIP158ForkBlock": "0x28d138",
		"byzantiumForkBlock": "0x42ae50",
		"constantinopleForkBlock": "0x500000",
		"networkID" : "0x20200522",
		"chainID": "0x20200522",
		"maximumExtraDataSize": "0x20",
		"tieBreakingGas": false,
		"minGasLimit": "0x1388",
		"maxGasLimit": "7fffffffffffffff",
		"gasLimitBoundDivisor": "0x0400",
		"minimumDifficulty": "0x020000",
		"difficultyBoundDivisor": "0x0800",
		"durationLimit": "0x0d",
		"blockReward": "0x00"
	},
	"genesis": {
		"nonce": "0x0000000000000042",
		"difficulty": "0x100000",
		"mixHash": "0x0000000000000000000000000000000000000000000000000000000000000000",
		"author": "0x0000000000000000000000000000000000000000",
		"timestamp": "0x00",
		"parentHash": "0x0000000000000000000000000000000000000000000000000000000000000000",
		"extraData": "0x11bbe8db4e347b4e8c937c1c8370e4b5ed33adb3db69cbdb7a38e1e50b1b82fa",
		"gasLimit": "0x989680"
	},
  "accounts": {
    "834d078f39a8799e5c8611843befd8538ddb049c": {
        "balance" : "0x8af7623fb67bf000000000"
    }
  }
}
)E";
