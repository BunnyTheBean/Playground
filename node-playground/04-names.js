// local
const secret = "SUPER SECRET";

// shared
const john = "john";
const peter = "peter";

// sharing the objects in the exports object
// keys are apparently added automatically as the variable's names
module.exports = {john, peter};

// console.log(module);