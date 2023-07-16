#include "style.h"


QString Style::getStyleButtons() {
    return "QPushButton {"
           "color: #0f0;"
           "background-color: #555;"
           "border: 2px solid #555;"
           "}"
           "QPushButton::hover {"
           "background-color: #888;"
           "border: 2px solid #555;"
           "}";
}
