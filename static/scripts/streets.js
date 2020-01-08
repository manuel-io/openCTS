class Map {
  camera = { 'x': 0
           , 'y': 0
           , 'w': 0
           , 'h': 0
           };

  static getCoordinatesOnMap(x, y) {
    var xpos = Map.camera.x + 64 * (x - y);
    var ypos = Map.camera.y + 32 * (x + y);
    return [xpos, ypos]
  }

  constructor(canvas) {
    this.canvas = canvas;
    this.canvas.setAttribute('width', this.canvas.clientWidth);
    this.canvas.setAttribute('height', canvas.clientHeight);
    this.ctx = canvas.getContext("2d");
    this.ctx.scale(1, 1);

    this.width = 30;
    this.height = 30;
    this.mouse = { 'x': 0, 'y': 0 };
    Map.camera = { 'x': 0
                    , 'y': 0
                    , 'w': this.canvas.width
                    , 'h': this.canvas.height
                    };
 
    this.base = { 'img': new Image(), 'dat': {} };
    this.base.img.src = '/static/assets/base.png';
    this.select = { 'img': new Image(), 'dat': {} };
    this.select.img.src = '/static/assets/select.png';

    /* init empty map, or load a map */
    this.map = Array(this.width * this.height);
    for (var y = 0; y < this.height; y++) {
      for (var x = 0; x < this.width; x++) {
        this.map[y * this.height + x] = this.base;
      }
    }
  }

  handle(event) {
  }

  static getCoordinates(x, y) {
    var xpos = 64 * (x - y);
    var ypos = 32 * (x + y);
    return [xpos, ypos]
  }

  getCoordinates(x, y) {
    var xpos = Map.camera.x + 64 * (x - y);
    var ypos = Map.camera.y + 32 * (x + y);
    return [xpos, ypos]
  }

  getMouseOverMap() {
    var x = Math.floor((-Map.camera.y + (this.mouse.y) -64 + (-Map.camera.x + (this.mouse.x) -64) / 2) /64);
    var y = Math.floor((-Map.camera.x + (this.mouse.x) -64 - (-Map.camera.y + (this.mouse.y) -64) * 2) / -128);
    return this.getCoordinates(x, y).concat([x, y]);
  }

  setMap() {
    let [xpos, ypos, x, y] = this.getMouseOverMap();
    if (this.select.img) {
      this.map[y * this.height + x] = { 'img': this.select.img
                                      , 'dat': this.select.dat
                                      };
    }
  }

  drawMap() {
    var count = 0;
    this.ctx.clearRect(0, 0, this.canvas.width, this.canvas.height);

    for (var y = 0; y < this.height; y++) {
      for (var x = 0; x < this.width; x++) {
        var xmin = 0, xmax = Map.camera.w;
        var ymin = 0, ymax = Map.camera.h;
        let [xpos, ypos] = this.getCoordinates(x, y)

        /*
        this.ctx.beginPath();
        this.ctx.arc(xpos + 64, ypos + 64, 3, 0, 2 * Math.PI, true);
        this.ctx.fillStyle = "#ff0000";
        this.ctx.fill();
        */

        /* if tile is visible render it! */
        if(xpos + 128 >= xmin && xpos - 128 <= xmax && ypos + 128 >= ymin && ypos - 64 <= ymax) {
          var image = this.map[this.height * y + x].img
          this.ctx.beginPath();
          this.ctx.moveTo(xpos, ypos);
          this.ctx.drawImage(image, xpos, ypos, 128, 128);
          count++;
        }
      }
    }
    /* console.log('Rendered ' + count + ' of ' + (this.height * this.width)); */
  }

  drawTraffic(traffic) {
    console.log('simulate traffic');
    traffic.forEach((item, index) => {
      let line = item.line;
      let position = item.position;
      let route = line.route[item.route].path;
      let [xpos, ypos] = this.getCoordinates(...line.route[item.route].map);
      let [[x1,y1], [x2,y2]] = route.route
      console.log(line);
      console.log([x1,y1]);
      console.log([x2,y2]);
      console.log("xpos:" + xpos);
      console.log("ypos:" + ypos);

      //this.ctx.beginPath();
      //this.ctx.arc(xpos + x1 + Math.floor(position * (x2 - x1)/route.cell), ypos + y1 + Math.floor(position * (y2 - y1)/route.cell), 3, 0, 2 * Math.PI, true);
      //this.ctx.fillStyle = "#ff0000";
      //this.ctx.fill();
      //
      if (route.angle == 135) {
        var image = item.sprite.a;
      }
      if (route.angle == 315) {
        var image = item.sprite.c;
      }
      if (route.angle == 225) {
        var image = item.sprite.b;
      }
      if (route.angle == 45) {
        var image = item.sprite.d;
      }
      var xset = xpos + x1 + Math.floor(position * (x2 - x1)/route.cell);
      var yset = ypos + y1 + Math.floor(position * (y2 - y1)/route.cell);
      this.ctx.beginPath();
      this.ctx.drawImage(image, xset - 55, yset - 90, 128, 128);

      console.log('position: ' + position);
      console.log('cells: ' + route.cell);

      if (position >= route.cell) {
        item.position = 1;
        if (item.route >= line.route.length - 1) {
          console.log('amount: ' + line.route.length);
          item.route = 0;
        }
        else item.route += 1;
      }
      else item.position += 0.2;
    });
  }

  drawSelect() {
    let [xpos, ypos, x, y] = this.getMouseOverMap();
    if (this.select.img) {
      var image = this.select.img;
      this.ctx.beginPath();
      this.ctx.moveTo(xpos, ypos);
      this.ctx.drawImage(image, xpos, ypos, 128, 128);
    }
  }

  drawNode() {
    let [xpos, ypos, xmap, ymap] = this.getMouseOverMap();
    let street = this.map[ymap * this.height + xmap];
    let view = { 'x': this.mouse.x, 'y': this.mouse.y };

    if (street.dat.paths) {
      var points = street.dat.paths.map((path, index) => {
        let [x, y] = path.point;
        let dist = Math.sqrt(((view.x - x - xpos) * (view.x - x - xpos)) + ((view.y - y - ypos) * (view.y - y - ypos)));
        return { "index": index, "point": path.point, "dist": dist};
      });

      var first = points.shift();
      var selected = points.reduce((acc, item) => {
        let [x, y] = item.point;
        let dist = Math.sqrt(((view.x - x - xpos) * (view.x - x - xpos)) + ((view.y - y - ypos) * (view.y - y - ypos)));
        item.dist = dist;
        if (item.dist < acc.dist) return item;
        else return acc;
      }, first);

      let [x, y] = selected.point;

      this.ctx.beginPath();
      this.ctx.arc(xpos + x, ypos + y, 3, 0, 2 * Math.PI, true);
      this.ctx.fillStyle = "#ff0000";
      this.ctx.fill();

      this.select = { "map": [xmap, ymap]
                    , "path": street.dat.paths[selected.index]
                    }
    }
  }
  
  drawLine(paths) {
    paths.forEach((item, index) => {
      let [xpos, ypos] = this.getCoordinates(item.map[0], item.map[1]);
      let [[x1, y1], [x2, y2]] = item.path.route;

      this.ctx.beginPath();
      this.ctx.moveTo((xpos + x1), (ypos + y1));
      this.ctx.lineTo((xpos + x2), (ypos + y2));
      this.ctx.strokeStyle = "#ff0000";
      this.ctx.stroke();
    }); 
  }

  drawSprites(sprites) {
    sprites.forEach((sprite) => {
      sprite.draw(this.ctx);
    });
  }

  drawStreet() {
    for (var y = 0; y < this.height; y++) {
      for (var x = 0; x < this.width; x++) {
        var street = this.map[y * this.height + x]
        let [xpos, ypos] = this.getCoordinates(x, y);

        if (street.dat.paths) {
          street.dat.paths.forEach((path) => {
            let [x, y] = path.point;

            this.ctx.beginPath();
            this.ctx.arc(xpos + x, ypos + y, 3, 0, 2 * Math.PI, true);
            this.ctx.fillStyle = "#ff0000";
            this.ctx.fill();
          });
        }
        
        if (street.dat.paths) {
          street.dat.paths.forEach((path) => {
              let [[x, y],[u, v]] = path.route;
            
              this.ctx.beginPath();
              this.ctx.moveTo((xpos + x), (ypos + y));
              this.ctx.lineTo((xpos + u), (ypos + v));
              this.ctx.strokeStyle = "#0000ff";
              this.ctx.stroke();
          });
        }
      }
    }
  }
}

class Sprite {
  constructor(line,sprite) {
    this.line = line;
    this.sprite = sprite;
  }

  draw(ctx) {
    let [xpos, ypos] = Map.getCoordinatesOnMap(0,0);
    ctx.beginPath();
    ctx.moveTo(xpos, ypos);
    ctx.drawImage(this.sprite['a'], xpos, ypos, 256, 256);
  }
  
}

class Game {

  static load(next) {
    var count = 0;
    var ref_count = 0;
    var data = { 'streets': []
               , 'autobuses': []
               }

    fetch('/data')
      .then(response => response.json())
      .then(response => {
        response.streets.forEach((street, index) => {
          console.log('streets', index);
          console.log(street.paths);
          ref_count++;
          var object = { 'img': new Image()
                       , 'dat': street
                       }
          object.img.src = '/streets/' + street.uid;
          object.img.onload = () => count++;
          data['streets'].push(object);
        });

        response.autobuses.forEach((bus, index) => {
          console.log('autobuses', index);
          ref_count += 4;
          var object = { 'title': bus.title
                       , 'seats': bus.seats
                       , 'standing': bus.standing
                       , 'a': new Image()
                       , 'b': new Image()
                       , 'c': new Image()
                       , 'd': new Image()
                       }

          object.a.src = '/autobuses/' + bus.uid + '/a';
          object.a.onload = () => count++;
          object.b.src = '/autobuses/' + bus.uid + '/b';
          object.b.onload = () => count++;
          object.c.src = '/autobuses/' + bus.uid + '/c';
          object.c.onload = () => count++;
          object.d.src = '/autobuses/' + bus.uid + '/d';
          object.d.onload = () => count++;

          data['autobuses'].push(object);
        });

        Game._load_img(() => {
          /* wait until all images are loaded */
          return count == ref_count;
        }, () => {
          return next(data);
        });
      });
  }

  static _load_img(check, next) {
    if (check()) next();
    else setTimeout(() => {
      Game._load_img(check, next);
    }, 100);
  }

  constructor(canvas, data) {
    this.mode = 1;
    this.data = data;
    this.sprites = [];
    this.map = new Map(canvas);

    this.traffic = new Array();

    this.lines = new Array();
    this.line = { "title": "Testline"
                , "start": new Array()
                , "route": new Array()
                }

    this.line_start = undefined;
    this.line_current = undefined;

    this.loop = () => { 
      switch(this.mode) {
        case 0:
          /* Game mode */
          this.map.drawMap();
          this.map.drawTraffic(this.traffic);
        break;
        case 1:
          /* Edit mode */
          this.map.drawMap();
          this.map.drawStreet();
          this.map.drawSelect();
          //this.map.drawSprites(this.sprites);
        break;
        case 2:
          /* Line mode */
          this.map.drawMap();
          this.map.drawNode();
          // this.map.drawTile();
          this.map.drawLine(this.line.route);
        break;
      }
    }

    this.handle = (event) => {
      if (event.type == 'click') {
        switch(this.mode) {
          case 0:
            /* Game mode */
          break;
          case 1:
            /* Edit mode */
            this.map.setMap();
          break;
          case 2:
            /* Line mode */
            let [xtile, ytile] = Map.getCoordinatesOnMap(...this.map.select.map);
            let [xroute, yroute] = [xtile + this.map.select.path.point[0], ytile + this.map.select.path.point[1]]
            if (!this.line.route.length) {
              this.line.start = [xroute, yroute]
              this.line.route.push(this.map.select);
              alert("Start");
            } else {
              console.log(this.line.start);
              console.log(xroute, yroute);
              if (xroute == this.line.start[0] && yroute == this.line.start[1]) {
                  alert("Finished");
                  this.lines.push(this.line);
                  this.traffic.push({ "line": this.line
                                    , "route": 0
                                    , "position": 1
                                    , "sprite": this.data.autobuses[0]
                                    });
                  console.log(this.lines);
              } else {
                this.line.route.push(this.map.select);
              }
            }

          break;
        }
      }

      if (event.type == 'keyup') {
        switch(event.keyCode) {
          case 37:
            Map.camera.x += 100;
          break;
          case 38:
            Map.camera.y += 100;
          break;
          case 39:
            Map.camera.x -= 100;
          break;
          case 40:
            Map.camera.y -= 100;
          break;
        }
      }

      if (event.type == 'mousemove') {
        let bounds = this.map.canvas.getBoundingClientRect();
        this.map.mouse.x = event.clientX - bounds.left - this.map.canvas.clientLeft;
        this.map.mouse.y = event.clientY - bounds.top - this.map.canvas.clientTop;
      }
      //console.log(event.type);
      //this.map.handle(event);
    }
  }
}

class Menu {
  constructor(game, data) {
    console.log('Menu');
    this.game = document.getElementById('game');
    this.edit = document.getElementById('edit');
    this.line = document.getElementById('line');
    this.clear = document.getElementById('clear');
    this.streets = document.getElementById('streets');
    data.streets.forEach((street, index) => {
      var option = document.createElement('option');
      option.innerHTML = street.dat.title;
      option.value = index;
      this.streets.onchange = (val) => {
        var index = this.streets.options[this.streets.selectedIndex].value;
        game.map.select = data.streets[index];
      };
      this.streets.appendChild(option);
    });

    this.clear.onclick = () => {
      game.map.select = game.map.base;
    };

    this.game.onclick = () => {
      console.log('game mode');
      game.mode = 0;
    }

    this.edit.onclick = () => {
      console.log('edit mode');
      game.mode = 1;
    }

    this.line.onclick = () => {
      console.log('line mode');
      game.mode = 2;
    }
  }
}
