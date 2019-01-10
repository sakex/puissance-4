#include <node.h>
#include <Game.h>
#include <AI.h>
#include <iostream>
#include <vector>

using v8::Array;
using v8::Exception;
using v8::External;
using v8::FunctionCallbackInfo;
using v8::FunctionTemplate;
using v8::Local;
using v8::Number;
using v8::Object;
using v8::ObjectTemplate;
using v8::PropertyCallbackInfo;
using v8::String;
using v8::Value;

void play(const FunctionCallbackInfo<Value> &args)
{
  v8::Isolate *isolate = v8::Isolate::GetCurrent();

  Local<Object> self = args.Holder();
  Local<External> wrapper = Local<External>::Cast(self->GetInternalField(0));
  Game *game = static_cast<Game *>(wrapper->Value());
  short row = args[0]->NumberValue();
  short column = game->play(row);
  if (column != -1)
  {
    short winner = game->findWinner(column, row);
    Local<Array> output = Array::New(isolate);
    output->Set(0, Number::New(isolate, column));
    output->Set(1, Number::New(isolate, row));
    output->Set(2, Number::New(isolate, game->getPlayer()));
    output->Set(3, Number::New(isolate, winner));
    game->nextPlayer();
    args.GetReturnValue().Set(output);
  }
  else
    args.GetReturnValue().Set(Number::New(isolate, -1));
}

void print(const FunctionCallbackInfo<Value> &args)
{
  Local<Object> self = args.Holder();
  Local<External> wrapper = Local<External>::Cast(self->GetInternalField(0));
  Game *game = static_cast<Game *>(wrapper->Value());
  game->printState();
}

void minimax(const FunctionCallbackInfo<Value> &args)
{
  v8::Isolate *isolate = v8::Isolate::GetCurrent();
  Local<Object> self = args.Holder();
  Local<External> wrapper = Local<External>::Cast(self->GetInternalField(0));
  Game *game = static_cast<Game *>(wrapper->Value());
  short move = AI::MDP(game, 9);
  args.GetReturnValue().Set(Number::New(isolate, move));
}

void deleteGame(const FunctionCallbackInfo<Value> &args)
{
  Local<Object> self = args.Holder();
  Local<External> wrapper = Local<External>::Cast(self->GetInternalField(0));
  Game *game = static_cast<Game *>(wrapper->Value());
  delete &game;
}

void newGame(const FunctionCallbackInfo<Value> &args)
{
  v8::Isolate *isolate = v8::Isolate::GetCurrent();
  Game *game_ptr = new Game();
  game_ptr->nextPlayer();

  Local<ObjectTemplate> game_template = ObjectTemplate::New(isolate);
  game_template->SetInternalFieldCount(1);
  game_template->Set(isolate, "play", FunctionTemplate::New(isolate, play));
  game_template->Set(isolate, "print", FunctionTemplate::New(isolate, print));
  game_template->Set(isolate, "minimax", FunctionTemplate::New(isolate, minimax));
  game_template->Set(isolate, "delete", FunctionTemplate::New(isolate, deleteGame));
  Local<Array> matrix = Array::New(isolate);
  for (int i = 0; i < HEIGHT; ++i)
  {
    Local<Array> temp = Array::New(isolate);
    for (int j = 0; j < WIDTH; ++j)
    {
      temp->Set(j, Number::New(isolate, 0));
    }
    matrix->Set(i, temp);
  }

  Local<Object> game = game_template->NewInstance();
  game->SetInternalField(0, External::New(isolate, game_ptr));
  game->Set(String::NewFromUtf8(isolate, "matrix"), matrix);

  args.GetReturnValue().Set(game);
}

void init(Local<Object> exports)
{ // exporter méthodes
  NODE_SET_METHOD(exports, "Game", newGame);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, init)