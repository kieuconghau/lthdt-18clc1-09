#include "cSetting.h"

/* Setting: Console window */
const bool cSetting::Console::SETTING_0(text_size(20));
const bool cSetting::Console::SETTING_1(remove_scroll_bar());
const bool cSetting::Console::SETTING_2(zoom_full_console_window());
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* Setting: Game screen */
const int cSetting::Game::TOP_LIMIT = 1;
const int cSetting::Game::BOT_LIMIT = get_console_height() - cSetting::Game::TOP_LIMIT - 1;
const int cSetting::Game::LEFT_LIMIT = 1;
const int cSetting::Game::RIGHT_LIMIT = get_console_width() - cSetting::Game::LEFT_LIMIT - 1;
const ecColor cSetting::Game::BORDER_COLOR = ecColor::WHITE;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/* Setting: Objects's design */
/* Car */
const char cSetting::Object::Car::BRICK_SHAPE = char(219);
const ecColor cSetting::Object::Car::BRICK_COLOR = ecColor::BLACK;
const int cSetting::Object::Car::N = 4;
const vector<char> cSetting::Object::Car::SHAPES({ char(220), char(219), char(219), char(220)
, cSetting::Object::Car::BRICK_SHAPE, cSetting::Object::Car::BRICK_SHAPE, cSetting::Object::Car::BRICK_SHAPE
, cSetting::Object::Car::BRICK_SHAPE, cSetting::Object::Car::BRICK_SHAPE, cSetting::Object::Car::BRICK_SHAPE
, cSetting::Object::Car::BRICK_SHAPE, cSetting::Object::Car::BRICK_SHAPE, cSetting::Object::Car::BRICK_SHAPE });

/* Truck */
const char cSetting::Object::Truck::BRICK_SHAPE = char(219);
const ecColor cSetting::Object::Truck::BRICK_COLOR = ecColor::BLACK;
const int cSetting::Object::Truck::N = 4;
const vector<char> cSetting::Object::Truck::SHAPES({ char(219), char(219), char(220), char(220)
, cSetting::Object::Truck::BRICK_SHAPE, cSetting::Object::Truck::BRICK_SHAPE, cSetting::Object::Truck::BRICK_SHAPE
, cSetting::Object::Truck::BRICK_SHAPE, cSetting::Object::Truck::BRICK_SHAPE, cSetting::Object::Truck::BRICK_SHAPE
, cSetting::Object::Truck::BRICK_SHAPE, cSetting::Object::Truck::BRICK_SHAPE, cSetting::Object::Truck::BRICK_SHAPE });

/* Train */
const char cSetting::Object::Train::BRICK_SHAPE = char(']');
const ecColor cSetting::Object::Train::BRICK_COLOR = ecColor::GREY;
const int cSetting::Object::Train::N = 35;
const vector<char> cSetting::Object::Train::SHAPES({ char(220), char(219), char(219), char(219), char(219), char(205)
, char(219), char(219), char(219), char(219), char(219), char(205)
, char(219), char(219), char(219), char(219), char(219), char(205)
, char(219), char(219), char(219), char(219), char(219), char(205)
, char(219), char(219), char(219), char(219), char(219), char(205)
, char(219), char(219), char(219), char(219), char(219)
, cSetting::Object::Train::BRICK_SHAPE, cSetting::Object::Train::BRICK_SHAPE, cSetting::Object::Train::BRICK_SHAPE
, cSetting::Object::Train::BRICK_SHAPE, cSetting::Object::Train::BRICK_SHAPE, cSetting::Object::Train::BRICK_SHAPE
, cSetting::Object::Train::BRICK_SHAPE, cSetting::Object::Train::BRICK_SHAPE, cSetting::Object::Train::BRICK_SHAPE });

/* Bird */
const char cSetting::Object::Bird::BRICK_SHAPE = char(219);
const ecColor cSetting::Object::Bird::BRICK_COLOR = ecColor::BLACK;
const int cSetting::Object::Bird::N = 4;
const vector<char> cSetting::Object::Bird::SHAPES{ char(223), char(220), char(220), char(223)
, cSetting::Object::Bird::BRICK_SHAPE, cSetting::Object::Bird::BRICK_SHAPE, cSetting::Object::Bird::BRICK_SHAPE
, cSetting::Object::Bird::BRICK_SHAPE, cSetting::Object::Bird::BRICK_SHAPE, cSetting::Object::Bird::BRICK_SHAPE
, cSetting::Object::Bird::BRICK_SHAPE, cSetting::Object::Bird::BRICK_SHAPE, cSetting::Object::Bird::BRICK_SHAPE };

/* Dinosaur */
const char cSetting::Object::Dinosaur::BRICK_SHAPE = char(219);
const ecColor cSetting::Object::Dinosaur::BRICK_COLOR = ecColor::BLACK;
const int cSetting::Object::Dinosaur::N = 4;
const vector<char> cSetting::Object::Dinosaur::SHAPES{ char(223), char(219), char(220), char(254)
, cSetting::Object::Dinosaur::BRICK_SHAPE, cSetting::Object::Dinosaur::BRICK_SHAPE, cSetting::Object::Dinosaur::BRICK_SHAPE
, cSetting::Object::Dinosaur::BRICK_SHAPE, cSetting::Object::Dinosaur::BRICK_SHAPE, cSetting::Object::Dinosaur::BRICK_SHAPE
, cSetting::Object::Dinosaur::BRICK_SHAPE, cSetting::Object::Dinosaur::BRICK_SHAPE, cSetting::Object::Dinosaur::BRICK_SHAPE };

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

cSetting::cSetting() {}

cSetting::~cSetting() {}
