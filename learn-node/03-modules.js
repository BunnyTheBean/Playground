// gotta remember if the export is an object or just a single function
const names = require('./04-names');
const sayHi = require('./05-util-module')
const data = require('./06-alternative-export')

// console.log(names.john);

// sayHi(names.john);
// sayHi(names.peter);

// for (item of data.items) {
//     console.log(item);
// }

// for (property in data.singlePerson) {
//     console.log(`${property} = ${data.singlePerson[property]}`);
// }

// executes module code when requiring it
require('./07-mind-whatever')