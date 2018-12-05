# styled-functors

> Reason React Native UI Primatives 

## Primatives 

* `<Box />`
* `<Flex />`
* `<T />` (text)

## Installation

`yarn add styled-functors`

Then, add `styled-functors` to your `bsconfig.json`.

## Example

```reason
open BsReactNative;
open StyledFunctors.Primatives;

let make = (_children, ~user: Server.user) => {
  ...component,
  render: _self =>
    <Flex p={`px(2.)} grow=true content=`center>
      <Flex p={`py(6.)}>
        <Flex p={`px(12.)}>
          <T f={`size(4.)} color=Palatte.white> {user.firstName |> str} </T>
        </Flex>
        <Box> Media.playerImage </Box>
      </Flex>
      <Flex grow=true content=`center p={`px(2.)} m={`mb(6.)}>
        <T color=Palatte.semiTransparent f={`size(2.0)}>
          {user.schoolName |> String.uppercase |> str}
        </T>
      </Flex>
    </Flex>,
};

```

## Thoughts

Honestly not sure about this API. It was born out of prototyping needs - something where I could manipulate styles inline quickly. 

Sure it's verbose, but have you seen styling in Reason?

## Further Reading 

* http://2ality.com/2018/01/polymorphic-variants-reasonml.html

License
---
Mit
