// File Line: 28
// RVA: 0x957F0
void __fastcall Illusion::ParamOverride::SetOverride(Illusion::ParamOverride *this, unsigned int param_uid, unsigned int resource_type_name_uid, unsigned int override_name_uid, Illusion::ParamOverride::Condition condition, unsigned int original_name_uid)
{
  int v6; // er10
  unsigned int v7; // esi
  Illusion::ParamOverride *v8; // rdi
  int v9; // er11
  int v10; // eax
  unsigned int v11; // ecx
  unsigned __int16 v12; // ax

  v6 = Illusion::gStateSystem.mCurrentParamIndex;
  v7 = resource_type_name_uid;
  v8 = this;
  if ( Illusion::gStateSystem.mCurrentParamIndex > 0 )
  {
    v9 = 0;
    if ( Illusion::gStateSystem.mCurrentParamIndex >= 0 )
    {
      do
      {
        v10 = (v6 + v9) / 2;
        v11 = Illusion::gStateSystem.mStateParamLookup[v10].mNameUID;
        if ( param_uid <= v11 )
        {
          if ( param_uid >= v11 )
          {
            v12 = Illusion::gStateSystem.mStateParamLookup[v10].mParamIndex;
            goto LABEL_9;
          }
          v6 = v10 - 1;
        }
        else
        {
          v9 = v10 + 1;
        }
      }
      while ( v9 <= v6 );
    }
  }
  v12 = 0;
LABEL_9:
  v8->mConstantBlock = 0i64;
  v8->mStateParamIndex = v12;
  v8->mConstantBlockSize = 0;
  v8->mOverrideResourceHandle.mTypeUID = resource_type_name_uid;
  v8->mOverrideResourceHandle.mNameUID = override_name_uid;
  v8->mCondition = condition;
  UFG::qResourceHandle::Init(
    (UFG::qResourceHandle *)&v8->mOverrideResourceHandle.mPrev,
    v8->mOverrideResourceHandle.mTypeUID,
    v8->mOverrideResourceHandle.mNameUID);
  v8->mOriginalResourceHandle.mNameUID = original_name_uid;
  v8->mOriginalResourceHandle.mTypeUID = v7;
  UFG::qResourceHandle::Init(
    (UFG::qResourceHandle *)&v8->mOriginalResourceHandle.mPrev,
    v8->mOriginalResourceHandle.mTypeUID,
    v8->mOriginalResourceHandle.mNameUID);
}

// File Line: 57
// RVA: 0x95A20
void __fastcall Illusion::ParamOverride::SetTextureOverride(Illusion::ParamOverride *this, unsigned int param_uid, unsigned int override_name_uid, Illusion::ParamOverride::Condition condition, unsigned int original_name_uid)
{
  Illusion::ParamOverride::SetOverride(this, param_uid, 0x8B43FABF, override_name_uid, condition, original_name_uid);
}

