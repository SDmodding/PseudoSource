// File Line: 52
// RVA: 0xA159C0
void __fastcall Illusion::ShaderUser::ShaderUser(Illusion::ShaderUser *this)
{
  UFG::qResourceHandle::qResourceHandle(&this->mOverride_OutputDepth);
  UFG::qResourceHandle::qResourceHandle(&this->mOverride_OutputDepthAlpha);
  UFG::qResourceHandle::qResourceHandle(&this->mOverride_OutputDepthAlphaWind);
  UFG::qResourceHandle::qResourceHandle(&this->mOverride_OutputDepthWind);
  UFG::qResourceHandle::qResourceHandle(&this->mOverride_OutputHighlight);
  UFG::qResourceHandle::qResourceHandle(&this->mShaderTemplateHandle);
}

