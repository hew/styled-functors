open BsReactNative.Style;
open BsReactNative.Platform;

[@bs.module "react-native-responsive-fontsize"]
external rf: float => float = "default";

let isWeb = () => {
  switch (os()) {
  | Android => false
  | IOS(_) => false
  | exception (UnknownPlatform(_string)) => true
  };
};

module Box =
  Functors.BoxView({
    type paddingType = [ | `p(float) | `px(float) | `py(float)];
    type marginType = [
      | `mt(float)
      | `mb(float)
      | `mr(float)
      | `ml(float)
    ];
    let baseStyle = [] /*display(Flex)  hmmmm   */;
    let getPaddStyle = spaceType =>
      switch (spaceType) {
      | `p(p) => [padding(Pct(p))]
      | `px(p) => [paddingRight(Pct(p)), paddingLeft(Pct(p))]
      | `py(p) => [paddingTop(Pct(p)), paddingBottom(Pct(p))]
      };
    let getMargStyle = marginType =>
      switch (marginType) {
      | `mt(m) => [marginTop(Pct(m))]
      | `mb(m) => [marginBottom(Pct(m))]
      | `mr(m) => [marginRight(Pct(m))]
      | `ml(m) => [marginLeft(Pct(m))]
      };
    let paddingStyle = spaceType =>
      switch (spaceType) {
      | Some(spaceType) => getPaddStyle(spaceType)
      | None => baseStyle
      };
    let marginStyle = marginType =>
      switch (marginType) {
      | Some(marginType) => getMargStyle(marginType)
      | None => baseStyle
      };
    let bgColorStyle = bg =>
      switch (bg) {
      | Some(bg) => [backgroundColor(String(bg))]
      | None => []
      };
    let style = (paddingType, marginType, bgColor) =>
      style(
        List.append(
          List.flatten([
            marginStyle(marginType),
            paddingStyle(paddingType),
            bgColorStyle(bgColor),
          ]),
          baseStyle,
        ),
      );
  });

module Flex =
  Functors.FlexView({
    type directionType = [ | `row | `column];
    type paddingType = [ | `p(float) | `px(float) | `py(float)];
    type marginType = [
      | `mt(float)
      | `mb(float)
      | `mr(float)
      | `ml(float)
    ];
    type flexType = [
      | `center
      | `centerX
      | `centerY
      | `right
      | `stretch
      | `around
    ];
    let baseStyle = [display(Flex)];
    let getFlexStyle = spaceType =>
      switch (spaceType) {
      | `center => [justifyContent(Center), alignItems(Center)]
      | `centerX => [alignItems(Center)]
      | `centerY => [justifyContent(Center)]
      | `right => [alignItems(FlexEnd)]
      | `stretch => [alignItems(Stretch)]
      | `around => [justifyContent(SpaceAround)]
      };
    let getPaddStyle = spaceType =>
      switch (spaceType) {
      | `p(p) => [padding(Pct(p))]
      | `px(p) => [paddingRight(Pct(p)), paddingLeft(Pct(p))]
      | `py(p) => [paddingTop(Pct(p)), paddingBottom(Pct(p))]
      };
    let getMargStyle = marginType =>
      switch (marginType) {
      | `mt(m) => [marginTop(Pct(m))]
      | `mb(m) => [marginBottom(Pct(m))]
      | `mr(m) => [marginRight(Pct(m))]
      | `ml(m) => [marginLeft(Pct(m))]
      };
    let getDirStyle = directionType =>
      switch (directionType) {
      | `row => [flexDirection(Row)]
      | `column => []
      };
    let dirStyle = directionType =>
      switch (directionType) {
      | Some(directionType) => getDirStyle(directionType)
      | None => []
      };
    let paddingStyle = spaceType =>
      switch (spaceType) {
      | Some(spaceType) => getPaddStyle(spaceType)
      | None => []
      };
    let marginStyle = marginType =>
      switch (marginType) {
      | Some(marginType) => getMargStyle(marginType)
      | None => []
      };
    let flexStyle = flexType =>
      switch (flexType) {
      | Some(flexType) => getFlexStyle(flexType)
      | None => []
      };
    let growStyle = growType =>
      switch (growType) {
      | Some(_growType) => [flex(1.)]
      | None => []
      };
    let bgColorStyle = bg =>
      switch (bg) {
      | Some(bg) => [backgroundColor(String(bg))]
      | None => []
      };
    let style =
        (paddingType, marginType, flexType, directionType, grow, bgColor) =>
      style(
        List.append(
          List.flatten([
            marginStyle(marginType),
            paddingStyle(paddingType),
            flexStyle(flexType),
            dirStyle(directionType),
            growStyle(grow),
            bgColorStyle(bgColor),
          ]),
          baseStyle,
        ),
      );
  });

module T =
  Functors.Text({
    type fontType = [ | `size(float)];
    type paddingType = [ | `p(float) | `px(float) | `py(float)];
    type marginType = [
      | `mt(float)
      | `mb(float)
      | `mr(float)
      | `ml(float)
    ];
    let baseStyle = [] /*display(Flex)  hmmmm   */;
    let getPaddStyle = spaceType =>
      switch (spaceType) {
      | `p(p) => [padding(Pct(p))]
      | `px(p) => [paddingRight(Pct(p)), paddingLeft(Pct(p))]
      | `py(p) => [paddingTop(Pct(p)), paddingBottom(Pct(p))]
      };
    let getMargStyle = marginType =>
      switch (marginType) {
      | `mt(m) => [marginTop(Pct(m))]
      | `mb(m) => [marginBottom(Pct(m))]
      | `mr(m) => [marginRight(Pct(m))]
      | `ml(m) => [marginLeft(Pct(m))]
      };
    let getFontStyle = fontType =>
      switch (fontType) {
      | `size(s) => [fontSize(Float(isWeb() ? s : rf(s)))]
      };
    let paddingStyle = spaceType =>
      switch (spaceType) {
      | Some(spaceType) => getPaddStyle(spaceType)
      | None => []
      };
    let marginStyle = marginType =>
      switch (marginType) {
      | Some(marginType) => getMargStyle(marginType)
      | None => []
      };
    let fontStyle = fontType =>
      switch (fontType) {
      | Some(fontType) => getFontStyle(fontType)
      | None => []
      };
    let colorStyle = color_ =>
      switch (color_) {
      | Some(color_) => [color(String(color_))]
      | None => []
      };
    let centerStyle = center =>
      switch (center) {
      | Some(_) => [textAlign(Center)]
      | None => []
      };
    let style = (paddingType, marginType, fontType, color, center) =>
      style(
        List.append(
          List.flatten([
            marginStyle(marginType),
            paddingStyle(paddingType),
            fontStyle(fontType),
            colorStyle(color),
            centerStyle(center),
          ]),
          baseStyle,
        ),
      );
  });
