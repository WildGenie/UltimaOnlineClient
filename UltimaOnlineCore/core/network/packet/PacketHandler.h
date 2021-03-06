//
//  PacketHandler.h
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 8/9/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#ifndef CORE_NETWORK_PACKET_PACKETHANDLER_H
#define CORE_NETWORK_PACKET_PACKETHANDLER_H

#include "ServerPacket.h"
#include "IPacketHandler.h"
#include <vector>

namespace core {
    namespace network {
        namespace packet {
            template <class T>
            class PacketHandler : public IPacketHandler {
            public:
                /* delegate method signature
                 @return TRUE if wants to process packet in others QUEUES, otherwise FALSE 
                 */
                typedef bool (T::*Operation)(core::network::packet::server::ServerPacket &packet);
                
                PacketHandler(T& target, Operation operation) : _target(target) , _operation(operation) {
                    _registerList = nullptr;
                }
                
                virtual bool handlePacket(core::network::packet::server::ServerPacket &packet) {
                    return (_target.*_operation)(packet);
                }
                
                virtual void setHandlerRegisterList(PacketHandlerList &registerList) {
                    _registerList = &registerList;
                }
                
                virtual bool deregisterHandler() {
                    if (this->_registerList != nullptr) {
                        auto endInterator = this->_registerList->end();
                        auto i = std::find(this->_registerList->begin(), endInterator, this);
                        if (i != endInterator) {
                            this->_registerList->erase(i);
                            return true;
                        }
                    }
                    return false;
                }
            private:
                T& _target;
                Operation _operation;
                PacketHandlerList *_registerList;
            };
        }
    }
}

#endif /* CORE_NETWORK_PACKET_PACKETHANDLER_H */
