//
// Created by permal on 7/22/17.
//

#pragma once

#include <smooth/application/network/mqtt/packet/MQTTPacket.h>

namespace smooth
{
    namespace application
    {
        namespace network
        {
            namespace mqtt
            {
                namespace packet
                {
                    class Subscribe
                            : public MQTTPacket
                    {
                        public:
                            Subscribe() = default;

                            Subscribe(const MQTTPacket& packet) : MQTTPacket(packet)
                            {
                            }

                            void visit(IPacketReceiver& receiver) override;
                        protected:
                            bool has_packet_identifier() const override
                            {
                                return true;
                            }

                            bool has_payload() const override
                            {
                                return true;
                            }
                    };
                }
            }
        }
    }
}
