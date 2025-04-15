// SPDX-FileCopyrightText: 2025 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/env.h"

namespace formo {

Env::Env() : msgr_(Message::DefaultMessenger()), printers_(msgr_->Printers())
{
    for (int idx = 0; idx < this->printers_.Size(); ++idx)
        this->msgr_->RemovePrinter(this->printers_.Value(idx + 1));
}

Env::~Env()
{
    for (int idx = 0; idx < this->printers_.Size(); ++idx)
        this->msgr_->AddPrinter(this->printers_.Value(idx + 1));
}

Env &
Env::instance()
{
    static Env env;
    return env;
}

} // namespace formo
