# styled-functors

> Write styles inline, using variant types.

## Motivations

I wanted to express something close to `styled-system` over in reason react native land.

## Roadmap

- [ ] Clean up types (rei, etc)
- [ ] Tests 

## Example

```reasonml

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

License
---
Mit
