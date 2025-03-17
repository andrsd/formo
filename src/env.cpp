// SPDX-FileCopyrightText: 2025 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/env.h"

namespace formo {

Env::Env() : msgr(Message::DefaultMessenger()), printers(msgr->Printers())
{
    for (int idx = 0; idx < this->printers.Size(); ++idx)
        this->msgr->RemovePrinter(this->printers.Value(idx + 1));
}

Env::~Env()
{
    for (int idx = 0; idx < this->printers.Size(); ++idx)
        this->msgr->AddPrinter(this->printers.Value(idx + 1));
}

Env &
Env::instance()
{
    static Env env;
    return env;
}

} // namespace formo
