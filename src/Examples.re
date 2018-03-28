let variant = {js|type animal =
  | Cat
  | Dog
  | Horse
  | ThreeHeadedMonkey;

let favoriteAnimal = ThreeHeadedMonkey;
  |js};

let variantWithData = {js|type shape =
  | Rectangle(int)
  | Square(int)
  | Circle(int);

let userShape = Rectangle(5);

type option('a) = Some('a) | None;
  |js};

let treeVariant = {js|type binaryTree =
  | Leaf(int)
  | Tree(binaryTree, binaryTree);

let myTree = Tree(
  Leaf(5),
  Tree(
    Leaf(2),
    Leaf(53)
  )
);
  |js};

let pattern = {js|let food = (animal) =>
  switch (animal) {
  | Cat => "Fish";
  | Dog => "Steak";
  | Horse => "Good ol' grass"
  | ThreeHeadedMonkey => "Three bananas";
  };

Js.log(food(favoriteAnimal));
/* "Three bananas" */
|js};

let patternInt = {js|let someNumber = 4;

let magicNumber = (n) =>
  switch (n) {
  | 8 => true
  | _ => false;
  };

Js.log(magicNumber(someNumber));
/* 0 */|js};

let tuples = {js|type position = (float, float);

let newYork = (40.712775, -73.989308);
let barcelona = (41.385063, 2.173403);
|js};

let records = {js|type position = {
  latitude: float,
  longitude: float,
};

let newYork = {
  latitude: 40.7127753,
  longitude: -73.989308
};
let barcelona = {
  latitude: 41.3850639,
  longitude: 2.1734035
};
let lat = barcelona.latitude;
let {latitude} = barcelona;
|js};

let tuplesOutput = {js|var newYork = /* tuple */[
  40.7127753,
  -73.989308
];

var barcelona = /* tuple */[
  41.3850639,
  2.1734035
];
|js};

let recordsOutput = {js|var newYork = /* float array */[
  40.7127753,
  -73.989308
];

var barcelona = /* float array */[
  41.3850639,
  2.1734035
];
|js};

let listAndArray = {js|/* Lists */
let games: list(string) =
  ["Mario", "Donkey Kong"];

let latestGames = ["Zelda BotW", ...games];

/* Arrays */
let characters: array(string) =
  [|"Cloud", "Barrett", "Tifa"|];

let first = characters[0];
|js};

let functions = {js|type position = {
  latitude: float,
  longitude: float,
};

let getLatitude = (position) => position.latitude;
  |js};

let functionsTwo = {js|let greetTwoPeople = (~first, ~second) => {
  let part1 = "Hello ";
  first ++ " and " ++ second
};|js};

let outputFunction = {js|function greetTwoPeople(first, second) {
  return "Hello " + (first + (" and " + second));
}|js};

let modules = {js|module BikeRental = {
  type bike = Kid | Mountain | City;

  let bikes = [];
  let getModelPrice = (bike) =>
    switch (bike) {
      | Kid => 123.0
      | Mountain => 250.0
      | City => 142.0
};|js};


let modulesFiles = {js|/* In BikeRental.re */
type bike = Kid | Mountain | City;

let bikes = [];
let getModelPrice = (bike) =>
  switch (bike) {
    | Kid => 123.0
    | Mountain => 250.0
    | City => 142.0
  };|js};

/* let modulesTwo = {js|module UserValidation = {
  type rawUser;
  type validatedUser;

  let validateUser(rawUser: rawUser): Some(validatedUser) => {
    /* Perform your validation */
    if (isValid(rawUser.name))
      Some(rawUser)
    else
    validatedUser;
  };|js}; */

let interop = {js|[%%bs.raw {|console.log('can inline javascript');|}];

let x: string = [%bs.raw {| 'well-typed' |}];

[@bs.val] external pi : float = "Math.PI";
Js.log(pi); /* console.log(Math.PI) */

[@bs.val] external random : unit => float = "Math.random";
random(); /* Math.random() */
|js};

let reasonReact = {js|let component = ReasonReact.statelessComponent("Greeting");
let s = ReasonReact.stringToElement;

let make = (~name, _children) => {
  ...component,
  render: _self =>
    <button>
      {s("Hello " ++ name ++ "!")}
    </button>
};|js};

let nativeCompilation = {js|#if BSB_BACKEND = "bytecode" then
/* run my native code */
#elif BSB_BACKEND = "native" then
/* run my native code */
#else
/* run my JavaScript code */
#end|js};