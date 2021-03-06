// Copyright (c) 2005 - 2017 Settlers Freaks (sf-team at siedler25.org)
//
// This file is part of Return To The Roots.
//
// Return To The Roots is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// Return To The Roots is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Return To The Roots. If not, see <http://www.gnu.org/licenses/>.
#ifndef MESSAGEQUEUE_H_INCLUDED
#define MESSAGEQUEUE_H_INCLUDED

#include "MessageHandler.h"
#include <boost/ptr_container/ptr_deque.hpp>
#include <cstddef>
#include <deque>
#include <queue>

class Message;
class Socket;

// class Socket;
class MessageQueue : protected MessageHandler
{
public:
    MessageQueue(CreateMsgFunction createfunction);
    MessageQueue(const MessageQueue& other);
    ~MessageQueue();
    MessageQueue& operator=(const MessageQueue& other);

    void clear();

    /// flusht die Queue, verschickt alle Elemente.
    bool flush(Socket& sock);

    /// liefert die Größe der Queue
    size_t size() const;
    bool empty() const;

    /// verschickt Pakete der Queue, maximal @p max, mit einem maximal @p sizelimit groß (aber beliebig viele kleine)
    bool send(Socket& sock, int max, unsigned sizelimit = 512);
    /// Receive (at most) a single message.
    /// If timeout is 0 then the function returns immediately after checking for a message
    /// Otherwise it keeps waiting for about that timeout till a complete message is received
    /// Returns the number of messages received or -1 on error
    int recv(Socket& sock, unsigned timeoutInMs = 0);
    /// Receive all complete messages. The timeout specifies the timeout for the first message (see recv)
    /// Returns the number of messages received or -1 on error
    int recvAll(Socket& sock, unsigned timeoutInMs = 0);
    /// Sends a message directly
    static bool sendMessage(Socket& sock, const Message& msg) { return MessageHandler::send(sock, msg) >= 0; }

    /// hängt ein Element hinten an.
    void push(Message* message);
    /// liefert das vorderste Element der Queue.
    Message* front();
    /// entfernt das vorderste Element aus der Queue.
    void pop();
    /// Returns the first element and removes it from the queue. Returns NULL if there is none
    /// Caller is responsible for deleting it!
    Message* popFront();

private:
    boost::ptr_deque<Message> messages;
};

#endif // LOBBYMESSAGEQUEUE_H_INCLUDED
