// File Line: 14
// RVA: 0x285D0
void __fastcall Render::ParseLightFromXML(SimpleXML::XMLNode *node, Render::Light *light)
{
  unsigned int v4; // eax
  const char *Attribute; // rax
  const char *v6; // rax
  int v7; // eax
  const char *v8; // rax
  unsigned int v9; // eax
  unsigned int v12; // [rsp+110h] [rbp+18h]
  char *string; // [rsp+118h] [rbp+20h]

  v4 = _S1_3;
  if ( (_S1_3 & 1) == 0 )
  {
    _S1_3 |= 1u;
    omniHash = UFG::qStringHash32("Omni", 0xFFFFFFFF);
    v4 = _S1_3;
  }
  if ( (v4 & 2) == 0 )
  {
    _S1_3 = v4 | 2;
    spotHash = UFG::qStringHash32("Spot", 0xFFFFFFFF);
    v4 = _S1_3;
  }
  if ( (v4 & 4) == 0 )
  {
    _S1_3 = v4 | 4;
    cardHash = UFG::qStringHash32("Card", 0xFFFFFFFF);
    v4 = _S1_3;
  }
  if ( (v4 & 8) == 0 )
  {
    _S1_3 = v4 | 8;
    spotlightshaftHash = UFG::qStringHash32("Spot_LightShaft", 0xFFFFFFFF);
  }
  Attribute = SimpleXML::XMLNode::GetAttribute(node, "name", "<unknown>");
  v12 = UFG::qStringHashUpper32(Attribute, 0xFFFFFFFF);
  v6 = SimpleXML::XMLNode::GetAttribute(node, "type", "<unknown>");
  v7 = UFG::qStringHash32(v6, 0xFFFFFFFF);
  if ( v7 == omniHash )
  {
    light->mType = 0;
  }
  else if ( v7 == spotHash )
  {
    light->mType = 1;
  }
  else if ( v7 == cardHash )
  {
    light->mType = 3;
  }
  else if ( v7 == spotlightshaftHash )
  {
    light->mType = 4;
  }
  string = (char *)SimpleXML::XMLNode::GetAttribute(
                     node,
                     "transform",
                     "1.0 0.0 0.0 0.0 0.0 1.0 0.0 0.0 0.0 0.0 1.0 0.0 0.0 0.0 0.0 1");
  sscanf(
    string,
    "%f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f",
    light,
    &light->mTransform.v0.y,
    &light->mTransform.v0.z,
    &light->mTransform.v0.w,
    &light->mTransform.v1,
    &light->mTransform.v1.y,
    &light->mTransform.v1.z,
    &light->mTransform.v1.w,
    &light->mTransform.v2,
    &light->mTransform.v2.y,
    &light->mTransform.v2.z,
    &light->mTransform.v2.w,
    &light->mTransform.v3,
    &light->mTransform.v3.y,
    &light->mTransform.v3.z,
    &light->mTransform.v3.w);
  v8 = SimpleXML::XMLNode::GetAttribute(node, "texture", &customCaption);
  if ( *v8 )
    v9 = UFG::qStringHashUpper32(v8, 0xFFFFFFFF);
  else
    v9 = -1;
  light->mTextureUID = v9;
  light->mLightID = v12;
  light->mColor.x = SimpleXML::XMLNode::GetAttribute(node, "colorR", 1.0);
  light->mColor.y = SimpleXML::XMLNode::GetAttribute(node, "colorG", 1.0);
  light->mColor.z = SimpleXML::XMLNode::GetAttribute(node, "colorB", 1.0);
  light->mDecayRadius = SimpleXML::XMLNode::GetAttribute(node, "decayRadius", 1.0);
  light->mDecayPower = SimpleXML::XMLNode::GetAttribute(node, "decayPower", 2.0);
  light->mShadowFlags = SimpleXML::XMLNode::GetAttribute(node, "shadowFlags", 0);
  light->mSpecular = SimpleXML::XMLNode::GetAttribute(node, "specular", 0);
  light->mFovHalfOuter = SimpleXML::XMLNode::GetAttribute(node, "fovOuter", 0.0);
  light->mFovHalfInner = SimpleXML::XMLNode::GetAttribute(node, "fovInner", 0.0);
  light->mShadowNear = SimpleXML::XMLNode::GetAttribute(node, "shadowNear", 0.1);
  light->mOnTime = SimpleXML::XMLNode::GetAttribute(node, "onTime", 18.0) * 3600.0;
  light->mOffTime = SimpleXML::XMLNode::GetAttribute(node, "offTime", 6.0) * 3600.0;
  light->mClipPlaneCount = 0;
  light->mDisableAnimation = 0;
  light->mBiasLightCard = SimpleXML::XMLNode::GetAttribute(node, "isBiased", 0);
  light->mTexDistAttenUID = -1;
  light->mTexDistAttenV = 0.0;
  if ( SimpleXML::XMLNode::GetAttribute(node, "LightShaftOn", 0) && light->mType == 1 )
    light->mType = 4;
}

