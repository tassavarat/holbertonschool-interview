#!/usr/bin/node
/**
 * Prints all characters of specified Star Wars movie
 * First argument is Movie ID
 */
const request = require('request');

function pchars (chars, i) {
  if (i === chars.length) return;
  request(chars[i], function (err, resp, body) {
    if (err) console.log(err);
    else {
      console.log(JSON.parse(body).name);
      pchars(chars, ++i);
    }
  });
}

request(`https://swapi-api.hbtn.io/api/films/${process.argv[2]}/`,
  function (err, resp, body) {
    if (err) console.log(err);
    else {
      const chars = JSON.parse(body).characters;
      pchars(chars, 0);
    }
  });
