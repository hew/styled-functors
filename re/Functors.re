open BsReactNative;

let get = (arg, default) =>
  switch (arg) {
  | None => default
  | Some(value) => value
  };

module type BoxConfig = {
  type paddingType;
  type marginType;
  let style:
    (option(paddingType), option(marginType), option(string)) => Style.t;
};

module BoxView = (Config: BoxConfig) => {
  let make =
      (~p=?, ~m=?, ~bgColor=?, ~style as additionalStyle=Style.(style([]))) =>
    View.make(
      ~style=Style.combine(Config.style(p, m, bgColor), additionalStyle),
    );
};

module type FlexConfig = {
  type paddingType;
  type marginType;
  type flexType;
  type directionType;
  let style:
    (
      option(paddingType),
      option(marginType),
      option(flexType),
      option(directionType),
      option(bool),
      option(string)
    ) =>
    Style.t;
};

module FlexView = (Config: FlexConfig) => {
  let make =
      (
        ~p=?,
        ~m=?,
        ~direction=?,
        ~content=?,
        ~grow=?,
        ~bgColor=?,
        ~style as additionalStyle=Style.(style([])),
      ) =>
    View.make(
      ~style=
        Style.combine(
          Config.style(p, m, content, direction, grow, bgColor),
          additionalStyle,
        ),
    );
};

module type TextConfig = {
  type paddingType;
  type marginType;
  type fontType;
  let style:
    (
      option(paddingType),
      option(marginType),
      option(fontType),
      option(string),
      option(bool),
    ) =>
    Style.t;
};

module Text = (Config: TextConfig) => {
  let make =
      (
        ~p=?,
        ~m=?,
        ~f=?,
        ~color=?,
        ~center=?,
        ~style as additionalStyle=Style.(style([])),
      ) =>
    Text.make(
      ~style=
        Style.combine(
          Config.style(p, m, f, color, center),
          additionalStyle,
        ),
    );
};
