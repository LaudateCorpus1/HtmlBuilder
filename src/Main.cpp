/**
 * @file    Main.cpp
 * @ingroup HtmlBuilder
 * @brief   A simple C++ HTML Generator library.
 *
 * Copyright (c) 2017 Sebastien Rombauts (sebastien.rombauts@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */

#include <HTML/HTML.h>

#include <iostream>

/**
 * @brief Entry-point of the application.
 */
int main() {
    HTML::Document document;
    document.head() << HTML::Title("Welcome to HTML");
    document << HTML::Header1("Welcome to HTML");
    document.body() << "Text directly in the body. ";
    document << HTML::Text("Text directly in the body. ") << HTML::Text("Text directly in the body.") << HTML::Break()
        << HTML::Text("Text directly in the body.");
    document << HTML::Paragraph("This is the way to go for a big text in a multiline paragraph.");
    document << HTML::Link("Google", "http://google.com").addAttribute("class", "my_style");
    document << HTML::Paragraph("A paragraphe. ").addAttribute("attr", "val").addAttribute("href", "http://my.com")
        .addChild(HTML::Text("Text child.")).addChild(HTML::Break()).addChild(HTML::Text("And more text."));

    document << (HTML::Table()
        << (HTML::Row() << HTML::Col("Cell_11") << HTML::Col("Cell_12"))
        << (HTML::Row() << HTML::Col("Cell_21") << HTML::Col("Cell_22")));

    std::cout << document;
    return 0;
}
