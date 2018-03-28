open BsSpectacle;

let theme =
  Theme.(
    createTheme(
      {
        primary: "#150939",
        secondary: "white",
        tertiary: "#FFD044",
        quarternary: "#14B3C4",
      },
      {
        primary: {
          name: "Muli",
          googleFont: true,
          styles: [|"300", "700"|],
        },
        secondary: {
          name: "Lobster Two",
          googleFont: true,
          styles: [|"400", "700"|],
        },
        tertiary: simpleFont("monospace"),
      },
    )
  );

type images = {
  blackhole: string,
  reason: string,
  fromJsToTyped: string,
  fromTypedToJs: string,
  fromJsToReasonToJs: string,
  reasonOcamlBuckleScript: string,
  undefinedIsNot: string,
};

let images: images = {
  blackhole: [%raw {| require('./assets/blackhole.jpg')|}],
  reason: [%raw {| require('./assets/reason.png')|}],
  fromJsToTyped: [%raw {| require('./assets/fromJsToTyped.svg')|}],
  fromTypedToJs: [%raw {| require('./assets/fromTypedToJs.svg')|}],
  fromJsToReasonToJs: [%raw {| require('./assets/fromJsToReasonToJs.svg')|}],
  reasonOcamlBuckleScript: [%raw
    {| require('./assets/Reason-OCaml-BuckleScript.svg')|}
  ],
  undefinedIsNot: [%raw {| require('./assets/undefinedIsNot.jpg')|}],
};

Preloader.load(images);

let s = ReasonReact.stringToElement;

type state = {steps: int};

type action =
  | UpdateSteps(int)
  | NoUpdate;

let component = ReasonReact.reducerComponent("Presentation");

let verySmallText = "1.6rem";

let smallText = "2rem";

let mediumText = "2.5rem";

let largeText = "3rem";

let make = _children => {
  ...component,
  initialState: () => {steps: 0},
  reducer: (action, _state) =>
    switch (action) {
    | UpdateSteps(steps) => ReasonReact.Update({steps: steps})
    | NoUpdate => ReasonReact.NoUpdate
    },
  render: ({state: _state, reduce: _reduce}) =>
    <Deck
      progress=`bar
      transition=[|Fade|]
      theme
      transitionDuration=500
      controls=false>
      <Slide notes="Typeform and Itnig">
        <Heading> "Thanks!" </Heading>
      </Slide>
      <Slide notes="-">
        <Heading> {j|👋|j} </Heading>
        <Text textColor="tertiary"> {j|Javier Chávarri|j} </Text>
        <Link href="https://twitter.com/javierwchavarri">
          <Text
            textColor="secondary"
            textSize=mediumText
            margin="0px auto 40px auto">
            "@javierwchavarri"
          </Text>
        </Link>
        <Text textColor="secondary" textSize=smallText>
          "Tech Lead @ Webflow"
        </Text>
        <Text textColor="secondary" textSize=smallText>
          "Contributor to OCaml language server and vscode-reasonml"
        </Text>
      </Slide>
      <Slide notes="-">
        <Image src=images.reason width="150px" margin="30px auto" />
        <Heading size=1 lineHeight=1.5> "Intro to Reason" </Heading>
        <Link href="https://github.com/jchavarri/intro-to-reason">
          <Text textSize=smallText textColor="secondary">
            {j|Slides built with Reason too! 🤓|j}
          </Text>
        </Link>
      </Slide>
      <Slide
        notes="How many people know Reason? How many have used it? TypeScript? Flow? Elm?">
        <Heading> {j|❓|j} </Heading>
        <Heading> "One question..." </Heading>
      </Slide>
      <Slide
        notes="How many people know 'undefined is not a function', talk about runtime checks vs compile time checks, and being in control"
        textAlign="center">
        <Heading> {j|🤔|j} </Heading>
        <Image src=images.undefinedIsNot width="750px" margin="60px auto" />
      </Slide>
      <Slide
        notes="The Quest to Typed-Land, how apps have become larger. History: JQuery, templates, MVC, v-dom, and now types">
        <Heading fit=true> "A story of two approaches" </Heading>
      </Slide>
      <Slide
        notes="Path 1: Improving JavaScript. Complexity, `any` types, familiarity. Don't think JS will ever have types.">
        <Heading fit=true> "Path 1: Improving JavaScript" </Heading>
        <Image src=images.fromJsToTyped width="750px" margin="60px auto" />
        <List>
          <Appear>
            <Text textSize=mediumText textColor="secondary">
              "Flow, TypeScript"
            </Text>
          </Appear>
        </List>
      </Slide>
      <Slide
        bgImage=images.blackhole
        bgDarken=0.55
        notes="How `any` affects good types (and libraries!). How the choice of supporting JS makes it impossible to do otherwise. ">
        <Heading fit=true> "Interlude: about `any`" </Heading>
      </Slide>
      <Slide
        notes="Can guarantee safety, more expressive, but might be farther from JS">
        <Heading fit=true> "Path 2: Compiling to JavaScript" </Heading>
        <Image src=images.fromTypedToJs width="750px" margin="60px auto" />
        <List>
          <Appear>
            <Text textSize=mediumText textColor="secondary">
              "Elm, PureScript, ClojureScript, Fable"
            </Text>
          </Appear>
        </List>
      </Slide>
      <Slide
        notes="Using JS syntax for familiarity, making interop really simple">
        <Heading fit=true>
          "Path 3: Influenced by JavaScript, compiles to JavaScript"
        </Heading>
        <Image
          src=images.fromJsToReasonToJs
          width="750px"
          margin="60px auto"
        />
      </Slide>
      <Slide notes="What is Reason and why">
        <Heading> "What and why" </Heading>
      </Slide>
      <Slide
        notes="Not a new language, Powered by OCaml (1996), New syntax and toolchain, Work backwards, Solid type system, Performance and size, Incremental learning & codebase conversion">
        <List>
          <Appear> <ListItem> "Not a new language" </ListItem> </Appear>
          <Appear> <ListItem> "Powered by OCaml (1996)" </ListItem> </Appear>
          <Appear> <ListItem> "New syntax and toolchain" </ListItem> </Appear>
          <Appear>
            <ListItem>
              "\"Work backwards\" from OCaml to JavaScript"
            </ListItem>
          </Appear>
          <Appear> <ListItem> "Solid type system" </ListItem> </Appear>
          <Appear> <ListItem> "Performance and size" </ListItem> </Appear>
          <Appear>
            <ListItem> "Incremental learning & codebase conversion" </ListItem>
          </Appear>
        </List>
      </Slide>
      <Slide notes="Every Reason program is a valid OCaml program">
        <Image
          src=images.reasonOcamlBuckleScript
          width="990px"
          margin="0px auto"
        />
      </Slide>
      <Slide notes="After a brief intro, this is what we'll be doing today">
        <Heading> "Summary" </Heading>
        <List>
          <ListItem> "Types & language features" </ListItem>
          <ListItem> "Interop" </ListItem>
          <ListItem> "Performance" </ListItem>
          <ListItem> "Native compilation" </ListItem>
          <ListItem> "ReasonReact" </ListItem>
          <ListItem> "Environment (IDEs, OSs...)" </ListItem>
        </List>
      </Slide>
      <Slide notes="-">
        <Heading> "Types & language features" </Heading>
      </Slide>
      <Slide notes="-"> <Heading> "Variant types" </Heading> </Slide>
      <Slide
        notes="Look like union types, but not the same thing. Types are inferred.">
        <CodePane
          lang="reason"
          bgColor="primary"
          source=Examples.variant
          textSize=smallText
          overflow="overflow"
        />
      </Slide>
      <Slide notes="Variants can also hold extra data">
        <CodePane
          lang="reason"
          bgColor="primary"
          source=Examples.variantWithData
          textSize=smallText
          overflow="overflow"
        />
      </Slide>
      <Slide notes="You can use more complex types, and any number of them">
        <CodePane
          lang="reason"
          bgColor="primary"
          source=Examples.treeVariant
          textSize=smallText
          overflow="overflow"
        />
      </Slide>
      <Slide notes="-"> <Heading> "Pattern matching" </Heading> </Slide>
      <Slide notes="Companion of variants">
        <CodePane
          lang="reason"
          bgColor="primary"
          source=Examples.pattern
          textSize=smallText
          overflow="overflow"
        />
      </Slide>
      <Slide notes="But works with any type">
        <CodePane
          lang="reason"
          bgColor="primary"
          source=Examples.patternInt
          textSize=smallText
          overflow="overflow"
        />
      </Slide>
      <Slide notes="-"> <Heading> "Tuples" </Heading> </Slide>
      <Slide notes="Immutable, fix size at creation, heterogeneous">
        <CodePane
          lang="reason"
          bgColor="primary"
          source=Examples.tuples
          textSize=smallText
          overflow="overflow"
        />
      </Slide>
      <Slide notes="-"> <Heading> "Records" </Heading> </Slide>
      <Slide
        notes="Like tuples, but with named fields. Immutable, fix size at creation, heterogeneous">
        <CodePane
          lang="reason"
          bgColor="primary"
          source=Examples.records
          textSize=verySmallText
          overflow="overflow"
        />
      </Slide>
      <Slide notes="Compilation of tuples and records to JS. Both are arrays.">
        <CodePane
          lang="javascript"
          bgColor="primary"
          source=Examples.tuplesOutput
          textSize=smallText
          overflow="overflow"
        />
      </Slide>
      <Slide notes="Compilation of tuples and records to JS. Both are arrays.">
        <CodePane
          lang="javascript"
          bgColor="primary"
          source=Examples.recordsOutput
          textSize=smallText
          overflow="overflow"
        />
      </Slide>
      <Slide notes="Lists immutable, arrays mutable">
        <Heading> "Arrays and lists" </Heading>
      </Slide>
      <Slide
        notes="List imm, array mutable. List quick prepending. Arrays quick retrieval and updates. Mention Belt.">
        <CodePane
          lang="javascript"
          bgColor="primary"
          source=Examples.listAndArray
          textSize=smallText
          overflow="overflow"
        />
      </Slide>
      <Slide notes="-"> <Heading> "Functions" </Heading> </Slide>
      <Slide notes="Very similar to JS">
        <CodePane
          lang="javascript"
          bgColor="primary"
          source=Examples.functions
          textSize=smallText
          overflow="overflow"
        />
      </Slide>
      <Slide notes="Labelled arguments">
        <CodePane
          lang="javascript"
          bgColor="primary"
          source=Examples.functionsTwo
          textSize=smallText
          overflow="overflow"
        />
      </Slide>
      <Slide notes="Amazing output">
        <CodePane
          lang="javascript"
          bgColor="primary"
          source=Examples.outputFunction
          textSize="1.9rem"
          overflow="overflow"
        />
      </Slide>
      <Slide notes="-"> <Heading> "Modules" </Heading> </Slide>
      <Slide notes="Encapsulation. You can guarantee order of execution">
        <CodePane
          lang="javascript"
          bgColor="primary"
          source=Examples.modules
          textSize=smallText
          overflow="overflow"
        />
      </Slide>
      <Slide notes="Files as modules">
        <CodePane
          lang="javascript"
          bgColor="primary"
          source=Examples.modulesFiles
          textSize=smallText
          overflow="overflow"
        />
      </Slide>
      <Slide notes="-"> <Heading> "Interop with JS" </Heading> </Slide>
      <Slide notes="Quick hacks but also solid typed JS">
        <CodePane
          lang="javascript"
          bgColor="primary"
          source=Examples.interop
          textSize=verySmallText
          overflow="overflow"
        />
      </Slide>
      <Slide notes="Bindings repository">
        <Heading> "Package index" </Heading>
        <Link href="https://redex.github.io/">
          <Text
            textColor="secondary"
            textSize=mediumText
            margin="60px auto 60px auto">
            "https://redex.github.io/"
          </Text>
        </Link>
      </Slide>
      <Slide notes="QUESTION - How many of you use React?">
        <Heading> "ReasonReact" </Heading>
      </Slide>
      <Slide notes="Typed props, interop, redux-like state">
        <CodePane
          lang="javascript"
          bgColor="primary"
          source=Examples.reasonReact
          textSize=verySmallText
          overflow="overflow"
        />
      </Slide>
      <Slide notes="Performance"> <Heading> "Performance" </Heading> </Slide>
      <Slide notes="Performance">
        <List>
          <ListItem>
            "Full rebuild of Facebook Messenger is ~2s (a few hundreds of files)"
          </ListItem>
          <Appear>
            <ListItem>
              "Incremental build (the norm) is <100ms on average."
            </ListItem>
          </Appear>
          <Appear>
            <ListItem>
              "Some data structures are faster than the JS native ones"
            </ListItem>
          </Appear>
        </List>
      </Slide>
      <Slide notes="Native compilation">
        <Heading fit=true> "Native compilation" </Heading>
        <Link href="https://gravitron.jaredforsyth.com/">
          <Text
            textColor="secondary"
            textSize=mediumText
            margin="60px auto 60px auto">
            {j|Gravitron: game for iOS 🍏, Android 👽 and web 🌍|j}
          </Text>
        </Link>
      </Slide>
      <Slide
        notes="Share 90% of the code, easily switch for the remaining 10%">
        <CodePane
          lang="javascript"
          bgColor="primary"
          source=Examples.nativeCompilation
          textSize=verySmallText
          overflow="overflow"
        />
      </Slide>
      <Slide notes="-">
        <Heading> "IDEs" </Heading>
        <List>
          <ListItem> "VSCode" </ListItem>
          <ListItem> "Atom" </ListItem>
          <ListItem> "Vim" </ListItem>
          <ListItem> "Emacs" </ListItem>
          <ListItem> "Sublime Text" </ListItem>
          <ListItem> "IDEA" </ListItem>
        </List>
      </Slide>
      <Slide notes="Ask for emails"> <Heading> "Questions" </Heading> </Slide>
      <Slide notes="-">
        <List>
          <ListItem>
            <Link textColor="tertiary" href="https://reasonml.github.io/">
              "Official documentation"
            </Link>
          </ListItem>
          <ListItem>
            <Link
              textColor="tertiary"
              href="https://codeburst.io/inference-engines-5-examples-with-typescript-flow-and-reason-edef2f4cf2d3">
              "5 examples with TypeScript, Flow and Reason"
            </Link>
          </ListItem>
          <ListItem>
            <Link
              textColor="tertiary"
              href="https://www.reaktor.com/blog/fear-trust-and-javascript/">
              "Fear, trust, and JavaScript, by Nicolas Kariniemi"
            </Link>
          </ListItem>
          <ListItem>
            <Link
              textColor="tertiary"
              href="https://bucklescript.github.io/docs/en/interop-cheatsheet.html">
              "Official BuckleScript docs - interop cheatsheet"
            </Link>
          </ListItem>
          <ListItem>
            <Link
              textColor="tertiary"
              href="https://jaredforsyth.com/posts/a-reason-react-tutorial/">
              "A ReasonReact tutorial, by Jared Forsyth"
            </Link>
          </ListItem>
        </List>
      </Slide>
      <Slide notes="Typeform and Itnig">
        <Heading> "Thank you!" </Heading>
        <Link href="https://twitter.com/javierwchavarri">
          <Text
            textColor="secondary"
            textSize=mediumText
            margin="40px auto 40px auto">
            "@javierwchavarri"
          </Text>
        </Link>
      </Slide>
    </Deck>,
};