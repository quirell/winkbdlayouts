//----------------------------------------------------------------------------
//
// Windows Keyboards Layouts (WKL)
// Copyright (c) 2023, Thierry Lelegard
// BSD-2-Clause license, see the LICENSE file.
//
// Base class for command line options.
//
//----------------------------------------------------------------------------

#pragma once
#include "strutils.h"

class Options
{
public:
    // Constructor.
    Options(int argc, wchar_t* argv[], const std::string syntax);

    // Command name and arguments.
    const std::wstring command;
    WStringVector      args;

    // Set an output file or use std::cout.
    void setOutput(const std::wstring& filename);
    void closeOutput();
    std::ostream& out() { return *_out; }
    
    // Prompt when exit() is called.
    void setPromptOnExit(bool on) { _prompt_on_exit = on; }

    // Exit process, prompt for user input if setPromptOnExit(true) was called.
    [[noreturn]] void exit(int status = EXIT_SUCCESS);

    // Print help and exits.
    [[noreturn]] void usage();

    // Print a fatal error and exit.
    [[noreturn]] void fatal(const std::wstring& message);

    // Print an error and continue.
    void error(const std::wstring& message);

private:
    const std::string _syntax;
    std::ofstream     _outfile;
    std::ostream*     _out;
    bool              _prompt_on_exit;
};
