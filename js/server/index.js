const app = require('express')();
const server = require('http').Server(app);
const io = require('socket.io')(server);
const next = require('next');

const socket = require('./socket.js');
socket(io);

const dev = process.env.NODE_ENV !== 'production'
const njs = next({
  dev
})

const handle = njs.getRequestHandler();

njs.prepare()
  .then(() => {
    app.get('*', (req, res) => {
      return handle(req, res)
    })

    server.listen(3000, (err) => {
      if (err) throw err
      console.log('> Ready on http://localhost:3000')
    })
  })
  .catch((ex) => {
    console.error(ex.stack)
    process.exit(1)
  })