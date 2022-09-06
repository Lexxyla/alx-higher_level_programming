#!/usr/bin/node
const dict = require('./101-data').dict;
const newDict = {};

Object.keys(dict).map(function (key, index) {
  if (newDict[dict[key]] === undefined) {
    newDict[dict[key]] = [];
  }
  newDict[dict[key]].push(key);
});

console.log(newDict);
