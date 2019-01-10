const P4 = require('../build/Release/Play');

const load = async socket => {
  let Game = new P4.Game();
  socket.on('play', row => {
    let move = Game.play(row + 1);
    if (move == -1)
      return;
    let [column, rowPlayed, player, winner] = move;
    Game.matrix[column][rowPlayed - 1] = player;
    socket.emit('update', Game.matrix);
    if (winner != 0) {
      Game = new P4.Game();
      socket.emit('winner', winner);
      return;
    }

    const AImove = Game.minimax();
    move = Game.play(AImove);
    [column, rowPlayed, player, winner] = move;
    Game.matrix[column][rowPlayed - 1] = player;
    socket.emit('update', Game.matrix);
    if (winner != 0) {
      socket.emit('winner', winner);
      Game = new P4.Game();
      return;
    }
  });
}

module.exports = io => {
  io.on('connection', load);
}