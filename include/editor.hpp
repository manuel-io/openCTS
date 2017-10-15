namespace Editor {

  class Items : public Form::Button {
  public:
    Items(const char *, const char *, int, int, int, int, int, int);
    ~Items();
    void handle(SDL_Event);
    void render();
  private:
    GameObject **objs;
    SDL_Rect rect = { .x = 190, .y = 570, .w = 610, .h = 130 };
    SDL_Color color;
    int scroll;
    int startpos, endpos;
  };

};
