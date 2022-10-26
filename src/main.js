// Build with `node ../dist/cli.js main.js --output-bytes`

import {exportToC, generate, importFromC} from './lib/ffi.js'

const intToString = importFromC('string', 'intToString', [['int','val']]);
const floatToString = importFromC('string', 'floatToString', [['float','val']]);
const floatLog = importFromC('void', 'floatLog', [['float', 'val']]);
const stringLog = importFromC('void', 'stringLog', [['string', 'val']]);
const emitAck = importFromC('void', 'emitAck', [['string', 'command']]);
const emitError = importFromC('void', 'emitError', [['string', 'command'], ['string', 'err']]);

function log(idx, fib) {
    // floatLog(fib);
    stringLog(`{"idx": ${intToString(idx++)}, "fib": ${floatToString(fib)}`);
}

function fibonacci(limit) {
  let idx = 0;

  let first = 0.0;
  log(idx++, first);

  let second = 1.0;
  log(idx++, second);

  let fib = 0.0;
  while (idx < limit) {
    fib = second + first;
    first = second;
    second = fib;
    log(idx++, fib);
  }
}

exportToC('void', 'fibonacci', [['int', 'limit']], fibonacci);

function command(command, payload) {
  console.log("got command " + command);
  console.log("with payload: " + payload);

  if (command === "fib") {
    emitAck(command);
    fibonacci(command, payload);
  } else {
    emitError(command, "unknown command: " + command);
  }
}

exportToC('void', 'command', [['string', 'command', 'string', 'payload']], command);

generate({
  appName: 'App',
  outDir: 'src/generated',
});
