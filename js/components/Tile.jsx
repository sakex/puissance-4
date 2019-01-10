import React, { useState } from 'react';
import Styled from 'styled-components';

const Border = Styled.div`
  width: ${props => props.size}px;
  height: ${props => props.size}px;
  background-color: blue;
  display: inline-block;
  margin: 0;
`;

const Content = Styled.div`
  width: ${props => props.size - 10}px;
  height: ${props => props.size - 10}px;
  border-radius: 50%;
  background-color: ${props => props.color};
  margin-top: 5px;
  margin-left: 5px;
  cursor: pointer;
`;

const Tile = props => {
  const play = () => {
    props.play(props.row);
  };

  let color;
  switch (props.value) {
    case 0:
      color = 'white';
      break;
    case 1:
      color = 'yellow';
      break;
    case 2:
      color = 'red';
      break;
  }
  return (
    <Border size={props.size}>
      <Content size={props.size} color={color} onClick={play} />
    </Border>
  );
};

export default Tile;
