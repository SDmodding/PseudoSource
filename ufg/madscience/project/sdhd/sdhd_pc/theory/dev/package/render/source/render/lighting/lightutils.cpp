// File Line: 14
// RVA: 0x285D0
void __fastcall Render::ParseLightFromXML(SimpleXML::XMLNode *node, Render::Light *light)
{
  Render::Light *v2; // r13
  SimpleXML::XMLNode *v3; // rbx
  unsigned int v4; // eax
  const char *v5; // rax
  const char *v6; // rax
  int v7; // eax
  const char *v8; // rax
  signed int v9; // eax
  SimpleXML::XMLNode *v10; // [rsp+100h] [rbp+8h]
  Render::Light *v11; // [rsp+108h] [rbp+10h]
  unsigned int v12; // [rsp+110h] [rbp+18h]
  char *string; // [rsp+118h] [rbp+20h]

  v11 = light;
  v10 = node;
  v2 = light;
  v3 = node;
  v4 = _S1_3;
  if ( !(_S1_3 & 1) )
  {
    _S1_3 |= 1u;
    omniHash = UFG::qStringHash32("Omni", 0xFFFFFFFF);
    v4 = _S1_3;
  }
  if ( !(v4 & 2) )
  {
    _S1_3 = v4 | 2;
    spotHash = UFG::qStringHash32("Spot", 0xFFFFFFFF);
    v4 = _S1_3;
  }
  if ( !(v4 & 4) )
  {
    _S1_3 = v4 | 4;
    cardHash = UFG::qStringHash32("Card", 0xFFFFFFFF);
    v4 = _S1_3;
  }
  if ( !(v4 & 8) )
  {
    _S1_3 = v4 | 8;
    spotlightshaftHash = UFG::qStringHash32("Spot_LightShaft", 0xFFFFFFFF);
  }
  v5 = SimpleXML::XMLNode::GetAttribute(v3, "name", "<unknown>");
  v12 = UFG::qStringHashUpper32(v5, 0xFFFFFFFF);
  v6 = SimpleXML::XMLNode::GetAttribute(v3, "type", "<unknown>");
  v7 = UFG::qStringHash32(v6, 0xFFFFFFFF);
  if ( v7 == omniHash )
  {
    v2->mType = 0;
  }
  else if ( v7 == spotHash )
  {
    v2->mType = 1;
  }
  else if ( v7 == cardHash )
  {
    v2->mType = 3;
  }
  else if ( v7 == spotlightshaftHash )
  {
    v2->mType = 4;
  }
  string = (char *)SimpleXML::XMLNode::GetAttribute(
                     v3,
                     "transform",
                     "1.0 0.0 0.0 0.0 0.0 1.0 0.0 0.0 0.0 0.0 1.0 0.0 0.0 0.0 0.0 1");
  sscanf(
    string,
    "%f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f",
    v11,
    &v11->mTransform.v0.y,
    &v11->mTransform.v0.z,
    &v2->mTransform.v0.w,
    &v2->mTransform.v1,
    &v2->mTransform.v1.y,
    &v2->mTransform.v1.z,
    &v2->mTransform.v1.w,
    &v2->mTransform.v2,
    &v2->mTransform.v2.y,
    &v2->mTransform.v2.z,
    &v2->mTransform.v2.w,
    &v2->mTransform.v3,
    &v2->mTransform.v3.y,
    &v2->mTransform.v3.z,
    &v2->mTransform.v3.w,
    -2i64);
  v8 = SimpleXML::XMLNode::GetAttribute(v10, "texture", &customWorldMapCaption);
  if ( *v8 )
    v9 = UFG::qStringHashUpper32(v8, 0xFFFFFFFF);
  else
    v9 = -1;
  v11->mTextureUID = v9;
  v11->mLightID = v12;
  v11->mColor.x = SimpleXML::XMLNode::GetAttribute(v10, "colorR", 1.0);
  v11->mColor.y = SimpleXML::XMLNode::GetAttribute(v10, "colorG", 1.0);
  v11->mColor.z = SimpleXML::XMLNode::GetAttribute(v10, "colorB", 1.0);
  v11->mDecayRadius = SimpleXML::XMLNode::GetAttribute(v10, "decayRadius", 1.0);
  v11->mDecayPower = SimpleXML::XMLNode::GetAttribute(v10, "decayPower", 2.0);
  v11->mShadowFlags = SimpleXML::XMLNode::GetAttribute(v10, "shadowFlags", 0);
  v11->mSpecular = SimpleXML::XMLNode::GetAttribute(v10, "specular", 0);
  v11->mFovHalfOuter = SimpleXML::XMLNode::GetAttribute(v10, "fovOuter", 0.0);
  v11->mFovHalfInner = SimpleXML::XMLNode::GetAttribute(v10, "fovInner", 0.0);
  v11->mShadowNear = SimpleXML::XMLNode::GetAttribute(v10, "shadowNear", 0.1);
  v11->mOnTime = SimpleXML::XMLNode::GetAttribute(v10, "onTime", 18.0) * 3600.0;
  v11->mOffTime = SimpleXML::XMLNode::GetAttribute(v10, "offTime", 6.0) * 3600.0;
  v11->mClipPlaneCount = 0;
  v11->mDisableAnimation = 0;
  v11->mBiasLightCard = SimpleXML::XMLNode::GetAttribute(v10, "isBiased", 0);
  v11->mTexDistAttenUID = -1;
  v11->mTexDistAttenV = 0.0;
  if ( SimpleXML::XMLNode::GetAttribute(v10, "LightShaftOn", 0) && v11->mType == 1 )
    v11->mType = 4;
}

