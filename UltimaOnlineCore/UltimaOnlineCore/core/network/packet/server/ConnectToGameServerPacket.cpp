//
//  ConnectToGameServerPacket.cpp
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/13/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#include "ConnectToGameServerPacket.h"
#include <stdio.h>
#include <string.h>

using namespace core::network::packet::server;

ConnectToGameServerPacket::ConnectToGameServerPacket() : ServerPacket(0x8C, 0) {
    _gameServerIP = nullptr;
}

ConnectToGameServerPacket::ConnectToGameServerPacket(const uint8_t *packetBuffer) : ServerPacket(packetBuffer) {
    _gameServerIP = new char[16];
    uint32_t ipAddress = this->unpack32(1);
    sprintf(_gameServerIP, "%d.%d.%d.%d",
            (ipAddress >> 24) & 0xFF,
            (ipAddress >> 16) & 0xFF,
            (ipAddress >>  8) & 0xFF,
            (ipAddress      ) & 0xFF);
}

ConnectToGameServerPacket::~ConnectToGameServerPacket() {
    if (_gameServerIP != nullptr)
        delete[] _gameServerIP;
}

const char* ConnectToGameServerPacket::getGameServerIP() {
    return _gameServerIP;
}

unsigned short ConnectToGameServerPacket::getGameServerPort() {
    return _gameServerPort;
}

unsigned int ConnectToGameServerPacket::getGameServerKey() {
    return _gameServerKey;
}

ServerPacket* ConnectToGameServerPacket::clone(const uint8_t *packetBuffer) {
    ConnectToGameServerPacket *cloned = new ConnectToGameServerPacket(packetBuffer);
    return cloned;
}
