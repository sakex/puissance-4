import React, { Component } from 'react';
import Styled from 'styled-components';
import socketio from 'socket.io-client';
import Tile from './Tile.jsx';

const socket = socketio();

const [HEIGHT, WIDTH] = [6, 7];

const Row = Styled.div`
  height: ${props => props.size}px;
`;

const Winner = Styled.h1`
  position: fixed;
  color: black;
  font-size: 30px;
  left: calc(50% - 15px);
  top: calc(50% - 15px);
`;

class Board extends Component {
  constructor(props) {
    super(props);
    this.matrix = [];
    for (var i = 0; i < HEIGHT; ++i) {
      const row = [];
      for (var j = 0; j < WIDTH; ++j) {
        row.push(0);
      }
      this.matrix.push(row);
    }

    this.state = {
      matrix: this.matrix,
      size: props.size
    };

    this.play = this.play.bind(this);
    this.loadSocket = this.loadSocket.bind(this);

    this.loadSocket();
  }

  play(row) {
    socket.emit('play', row);
  }

  render() {
    const matrix = this.state.matrix;
    const size = this.state.size / HEIGHT;
    const rows = [];
    for (var i = 0; i < HEIGHT; ++i) {
      const row = [];
      for (var j = 0; j < WIDTH; ++j) {
        row.push(
          <Tile
            play={this.play}
            value={matrix[i][j]}
            size={size}
            key={j}
            row={j}
          />
        );
      }
      rows.push(
        <Row size={size} key={i}>
          {row}
        </Row>
      );
    }

    return (
      <div>
        {this.state.winner && <Winner>{this.state.winner}</Winner>}
        {rows}
      </div>
    );
  }

  loadSocket() {
    socket
      .on('update', matrix => {
        this.setState({ matrix: matrix });
      })

      .on('winner', winner => {
        this.setState({ winner: winner });
      });
  }
}

export default Board;
