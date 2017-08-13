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
                    class PubComp
                            : public MQTTPacket
                    {
                        public:
                            PubComp() = default;

                            PubComp(const MQTTPacket& packet) : MQTTPacket(packet)
                            {
                            }

                            void visit(IPacketReceiver& receiver) override;

                            uint16_t get_packet_identifier() const;

                        protected:
                            bool has_packet_identifier() const override
                            {
                                return true;
                            }

                            int get_variable_header_length() const override
                            {
                                // Only packet identifier in this variable header
                                return 2;
                            }
                    };
                }
            }
        }
    }
}
