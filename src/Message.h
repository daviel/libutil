// Copyright (c) 2005 - 2015 Settlers Freaks (sf-team at siedler25.org)
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
#ifndef MESSAGE_H_INCLUDED
#define MESSAGE_H_INCLUDED

#pragma once

#include "Serializer.h"

class MessageInterface;
class Socket;

class Message : public Serializer
{
    public:
        /// Konstruktor von @p Message.
        Message(unsigned short id) : id_(id) {}
        /// Konstruktor, um Message aus vorhandenem Datenblock heraus zu erstellen
        Message(const unsigned id, const unsigned char* const data, const unsigned length) : Serializer(data, length), id_(id) {}

        virtual unsigned short getId() const { return id_; }
        bool send(Socket& sock);

        static Message* recv(Socket& sock, int& error, bool wait, Message * (*createfunction)(unsigned short));
        static Message* create_base(unsigned short id);

        virtual Message* create(unsigned short id) const { return create_base(id); }
        virtual Message* duplicate() const;

        virtual void run(MessageInterface* callback, unsigned int id) = 0;

    protected:
        Message(const Message& other): Serializer(other), id_(other.id_)
        {}

        Message& operator=(const Message& other)
        {
            if(this == &other)
                return *this;

            Serializer::operator =(other);
            id_ = other.id_;

            return *this;
        }

    private:
        int recv(Socket& sock, unsigned int length);

    protected:
        unsigned short id_;
};

#endif //!MESSAGE_H_INCLUDED
