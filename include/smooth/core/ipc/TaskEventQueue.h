//
// Created by permal on 6/27/17.
//

#pragma once

#include <smooth/core/Task.h>
#include "ITaskEventQueue.h"
#include "IEventListener.h"
#include "Link.h"

namespace smooth
{
    namespace core
    {
        namespace ipc
        {
            template<typename T>
            class TaskEventQueue
                    : public Link<T>, public ITaskEventQueue
            {
                public:
                    TaskEventQueue(const std::string& name, int size, Task& task, IEventListener<T>& listener)
                            :
                            Link<T>(),
                            task(task),
                            queue(name + std::string("-TaskEventQueue"), size),
                            listener(listener)
                    {
                        this->subscribe(&queue);
                        task.register_queue_with_task(this);
                    }


                    ~TaskEventQueue()
                    {
                        this->unsubscribe(&queue);
                    }

                    void forward_to_event_queue()
                    {
                        // All messages passed via a queue needs a default constructor
                        // and must be copyable and have the assignment operator.
                        T m;
                        if (queue.pop(m))
                        {
                            listener.event(m);
                        }
                    }

                    bool push(const T& item)
                    {
                        return queue.push(item);
                    }

                    int size()
                    {
                        return queue.size();
                    }

                    int count()
                    {
                        return queue.count();
                    }

                    QueueHandle_t get_handle()
                    {
                        return queue.get_handle();
                    }

                private:
                    Task& task;
                    Queue<T> queue;
                    IEventListener<T>& listener;
            };
        }
    }
}