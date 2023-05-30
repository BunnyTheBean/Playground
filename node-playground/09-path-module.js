const path = require('path');

console.log(path.sep);

const filePath = path.join('content', 'subfolder', 'test.txt');
console.log(filePath);

const base = path.basename(filePath);
console.log(`Base: ${base}`);

const absolutePath = path.resolve('content', 'subfolder', 'text.txt');
console.log(absolutePath);