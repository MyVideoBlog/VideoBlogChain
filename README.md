# VideoBlogChain  C++ client, tools and libraries


## Install

### Download release binaries

https://github.com/MyVideoBlog/VideoBlogChain/releases


### Building from source

#### Get the source code

Git and GitHub are used to maintain the source code. Clone the repository by:

```shell
git clone --recursive https://github.com/MyVideoBlog/VideoBlogChain.git
cd VideoBlogChain
```

The `--recursive` option is important. It orders git to clone additional
submodules to build the project.
If you missed `--recursive` option, you are able to correct your mistake with command
`git submodule update --init`.

#### Install CMake

CMake is used to control the build configuration of the project. Latest version of CMake is required
(at the time of writing [3.9.3 is the minimum](CMakeLists.txt#L5)).
We strongly recommend you to install CMake by downloading and unpacking the binary
distribution  of the latest version available on the
[**CMake download page**](https://cmake.org/download/).

The CMake package available in your operating system can also be installed
and used if it meets the minimum version requirement.

> **Alternative method**
>
> The repository contains the
[scripts/install_cmake.sh](scripts/install_cmake.sh) script that downloads
> a fixed version of CMake and unpacks it to the given directory prefix.
> Example usage: `scripts/install_cmake.sh --prefix /usr/local`.

####update g++6.0

`sudo apt-get update && \
sudo apt-get install build-essential software-properties-common -y && \
sudo add-apt-repository ppa:ubuntu-toolchain-r/test -y && \
sudo apt-get update && \
sudo apt-get install gcc-snapshot -y && \
sudo apt-get update && \
sudo apt-get install gcc-6 g++-6 -y && \
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-6 60 --slave /usr/bin/g++ g++ /usr/bin/g++-6 `
#### Build

Configure the project build with the following command to create the
`build` directory with the configuration.

```shell
mkdir build; cd build  # Create a build directory.
cmake ..               # Configure the project.
cmake --build .        # Build all default targets.
```

On **Windows** we support Visual Studio 2017, and 2019. You should generate a Visual Studio solution file (`.sln`) for the 64-bit architecture via the following command:

* **Visual Studio 2017**: `cmake .. -G "Visual Studio 15 2017 Win64"`
* **Visual Studio 2019**: `cmake .. -G "Visual Studio 16 2019" -A x64`

After the necessary dependencies have been downloaded and built and the solution has been generated, `aleth.sln` can be found in the
`build` directory.

#### Common Issues Building on Windows
##### LINK : fatal error LNK1158: cannot run 'rc.exe'
Rc.exe is the [Microsoft Resource Compiler](https://docs.microsoft.com/en-us/windows/desktop/menurc/resource-compiler). It's distributed with the [Windows SDK](https://developer.microsoft.com/en-US/windows/downloads/windows-10-sdk) and is required for generating the Visual Studio solution file. It can be found in the following directory: ```%ProgramFiles(x86)%\Windows Kits\<OS major version>\bin\<OS full version>\<arch>\```

If you hit this error, adding the directory to your path (and launching a new command prompt) should fix the issue.


## Usage
*Note: The following is the output of ```./aleth -h [--help]``` on Linux*

```
NAME:
   aleth 1.7.2
USAGE:
   aleth [options]

WALLET USAGE:
   account list                                List all keys available in wallet
   account new                                 Create a new key and add it to wallet
   account update [<uuid>|<address> , ... ]    Decrypt and re-encrypt keys
   account import [<uuid>|<file>|<secret-hex>] Import keys from given source and place in wallet
   wallet import <file>                        Import a presale wallet

CLIENT MODE (default):
  --mainnet                               Use the main network protocol
  --ropsten                               Use the Ropsten testnet
  --test                                  Testing mode; disable PoW and provide test rpc interface
  --config <file>                         Configure specialised blockchain using given JSON information

  --ipc                                   Enable IPC server (default: on)
  --ipcpath <path>                        Set .ipc socket path (default: data directory)
  --no-ipc                                Disable IPC server
  --admin <password>                      Specify admin session key for JSON-RPC (default: auto-generated and printed at start-up)
  -K [ --kill ]                           Kill the blockchain first
  -R [ --rebuild ]                        Rebuild the blockchain from the existing database
  --rescue                                Attempt to rescue a corrupt database

  --import-presale <file>                 Import a pre-sale key; you'll need to specify the password to this key
  -s [ --import-secret ] <secret>         Import a secret key into the key store
  -S [ --import-session-secret ] <secret> Import a secret session into the key store
  --master <password>                     Give the master password for the key store; use --master "" to show a prompt
  --password <password>                   Give a password for a private key

CLIENT TRANSACTING:
  --ask <wei>            Set the minimum ask gas price under which no transaction will be mined (default: 20000000000)
  --bid <wei>            Set the bid gas price to pay for transactions (default: 20000000000)
  --unsafe-transactions  Allow all transactions to proceed without verification; EXTREMELY UNSAFE

CLIENT NETWORKING:
  -b [ --bootstrap ]              Connect to the default Ethereum peer servers (default unless --no-discovery used)
  --no-bootstrap                  Do not connect to the default Ethereum peer servers (default only when --no-discovery is used)
  -x [ --peers ] <number>         Attempt to connect to a given number of peers (default: 11)
  --peer-stretch <number>         Give the accepted connection multiplier (default: 7)
  --public-ip <ip>                Force advertised public IP to the given IP (default: auto)
  --listen-ip <ip>(:<port>)       Listen on the given IP for incoming connections (default: 0.0.0.0)
  --listen <port>                 Listen on the given port for incoming connections (default: 30303)
  -r [ --remote ] <host>(:<port>) Connect to the given remote host (default: none)
  --port <port>                   Connect to the given remote port (default: 30303)
  --network-id <n>                Only connect to other hosts with this network id
  --allow-local-discovery         Include local addresses in the discovery process. Used for testing purposes.
  --peerset <list>                Comma delimited list of peers; element format: type:enode://publickey@ipAddress[:port[?discport=port]]
                                          Types:
                                          default     Attempt connection when no other peers are available and pinning is disabled
                                          required    Keep connected at all times

                                          Ports:
                                          The first port argument is the tcp port used for direct communication among peers. If the second port
                                          argument isn't supplied, the first port argument will also be the udp port used for node discovery.
                                          If neither the first nor second port arguments are supplied, a default port of 30303 will be used for
                                          both peer communication and node discovery.
  --no-discovery                  Disable node discovery; implies --no-bootstrap
  --pin                           Only accept or connect to trusted peers

CLIENT MINING:
  -a [ --address ] <addr>         Set the author (mining payout) address (default: auto)
  -m [ --mining ] <on/off/number> Enable mining; optionally for a specified number of blocks (default: off)
  --extra-data arg                Set extra data for the sealed blocks

BENCHMARKING MODE:
  -M [ --benchmark ]           Benchmark for mining and exit
  --benchmark-warmup <seconds> Set the duration of warmup for the benchmark tests (default: 3)
  --benchmark-trial <seconds>  Set the duration for each trial for the benchmark tests (default: 3)
  --benchmark-trials <n>       Set the number of trials for the benchmark tests (default: 5)

MINING CONFIGURATION:
  -C [ --cpu ]                 When mining, use the CPU
  -t [ --mining-threads ] <n>  Limit number of CPU/GPU miners to n (default: use everything available on selected platform)
  --current-block <n>          Let the miner know the current block number at configuration time. Will help determine DAG size and required GPU memory
  --disable-submit-hashrate    When mining, don't submit hashrate to node

IMPORT/EXPORT MODES:
  -I [ --import ] <file>      Import blocks from file
  -E [ --export ] <file>      Export blocks to file
  --from <n>                  Export only from block n; n may be a decimal, a '0x' prefixed hash, or 'latest'
  --to <n>                    Export only to block n (inclusive); n may be a decimal, a '0x' prefixed hash, or 'latest'
  --only <n>                  Equivalent to --export-from n --export-to n
  --format <binary/hex/human> Set export format
  --dont-check                Prevent checking some block aspects. Faster importing, but to apply only when the data is known to be valid
  --download-snapshot <path>  Download Parity Warp Sync snapshot data to the specified path
  --import-snapshot <path>    Import blockchain and state data from the Parity Warp Sync snapshot

DATABASE OPTIONS:
  --db <name> (=leveldb)      Select database implementation. Available options are: leveldb, memorydb.
  --db-path <path> (=$HOME/.ethereum) Database path (for non-memory database options)

VM OPTIONS:
  --vm <name>|<path> (=legacy) Select VM implementation. Available options are: interpreter, legacy.
  --evmc  <option>=<value>     EVMC option

LOGGING OPTIONS:
  -v [ --log-verbosity ] <0 - 4>        Set the log verbosity from 0 to 4 (default: 2).
  --log-channels <channel_list>         Space-separated list of the log channels to show (default: show all channels).
                                        Channels: block blockhdr bq chain client debug discov error ethcap exec host impolite info net overlaydb p2pcap peer
                                        rlpx rpc snap statedb sync timer tq trace vmtrace warn warpcap watch
  --log-exclude-channels <channel_list> Space-separated list of the log channels to hide.

  --log-vmtrace                         Enable VM trace log (requires log-verbosity 4).

GENERAL OPTIONS:
  -d [ --data-dir ] <path> Load configuration files and keystore from path (default: $HOME/.ethereum)
  -V [ --version ]         Show the version and exit
  -h [ --help ]            Show this help message and exit
```

## Start Node

aleth --no-discovery --config /home/root1/datadir/config.json  --listen 30303 --data-dir /home/root1/datadir/blockdata --db-path /home/root1/datadir/blockdata --peerset required:enode://815fbad4bb9e60bff95d36c6419987c85c8e15e46f78d7b67da49dbeb9b2824bf458117eeff03164b57684dcd78557b582b0bb023bffeafbde6256ec3567e6dc@47.57.164.0:30303

## config.json
```json
{
  "sealEngine": "Ethash",
	"params": {
		"accountStartNonce": "0x00",
		"homesteadForkBlock": "0x0",
		"daoHardforkBlock": "0x0",
		"EIP150ForkBlock": "0x0",
		"EIP158ForkBlock": "0x0",
		"byzantiumForkBlock": "0x0",
		"constantinopleForkBlock": "0x0",
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
```
## 启动RPC服务
./scripts/dopple.py  /home/root1/datadir/blockdata/geth.ipc   http://172.31.213.189:30304 

## Block Explorer

http://block.videoblog1.com/#/


