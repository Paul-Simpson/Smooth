//
// Created by permal on 6/27/17.
//

#pragma once

namespace smooth
{
    namespace  core
    {
        namespace ipc
        {
            /// Common interface for TaskEventQueue
            /// As an application programmer you are not meant to call any of these methods.
            class ITaskEventQueue
            {
                public:
                    /// Forwards the next event to the event queue
                    virtual void forward_to_event_queue() = 0;
                    /// Returns the size of the event queue.
                    virtual int size() = 0;
                    /// Returns the underlying FreeRTOS queue handle.
                    virtual QueueHandle_t get_handle() = 0;
            };
        }
    }
}
