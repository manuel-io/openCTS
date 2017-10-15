namespace Play {

  class Stats : public Form::Button {
  public:
    Stats(int x, int y, int w, int h) : Form::Button("Statistics", "assets/menu/stats.png", x, y, w, h) {};
    ~Stats() {};
  };

  class Market : public Form::Button {
  public:
    Market(int x, int y, int w, int h) : Form::Button("Market", "assets/menu/market.png", x, y, w, h) {};
    ~Market() {};
  };

  class Planer : public Form::Button {
  public:
    Planer(int x, int y, int w, int h) : Form::Button("Planer", "assets/menu/planer.png", x, y, w, h) {};
    ~Planer() {};
  };

  class Construction : public Form::Button {
  public:
    Construction(int x, int y, int w, int h) : Form::Button("Construction", "assets/menu/construction.png", x, y, w, h) {};
    ~Construction() {};
  };

  class Overview: public Form::Button {
  public:
    Overview(int x, int y, int w, int h) : Form::Button("Map", "assets/menu/map.png", x, y, w, h) {};
    ~Overview() {};
  };

  class Management : public Form::Button {
  public:
    Management(int x, int y, int w, int h) : Form::Button("Management", "assets/menu/management.png", x, y, w, h) {};
    ~Management() {};
  };
};
