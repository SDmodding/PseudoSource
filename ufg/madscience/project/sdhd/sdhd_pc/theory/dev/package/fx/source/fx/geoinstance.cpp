// File Line: 13
// RVA: 0x1CEAE0
void __fastcall Render::GeoInstance::Init(Render::GeoInstance *this, unsigned int settingsId)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v5; // rax
  UFG::qResourceData *mData; // rax
  unsigned int v7; // edi
  UFG::qResourceInventory *v8; // rax
  UFG::qResourceWarehouse *v9; // rax

  this->mSettingsId = settingsId;
  Inventory = `UFG::qGetResourceInventory<Render::GeoSettings>::`2::result;
  if ( !`UFG::qGetResourceInventory<Render::GeoSettings>::`2::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v5, 0xF1734D8E);
    `UFG::qGetResourceInventory<Render::GeoSettings>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&this->mSettingsHandle, 0xF1734D8E, settingsId, Inventory);
  mData = this->mSettingsHandle.mData;
  if ( mData )
  {
    v7 = *(_DWORD *)&mData[2].mDebugName[20];
    v8 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
    {
      v9 = UFG::qResourceWarehouse::Instance();
      v8 = UFG::qResourceWarehouse::GetInventory(v9, 0xA2ADCD77);
      `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v8;
    }
    UFG::qResourceHandle::Init(&this->mModelHandle, 0xA2ADCD77, v7, v8);
  }
}

// File Line: 30
// RVA: 0x1C63A0
void __fastcall Render::GeoInstance::Activate(Render::ScreenParticleEmitterInstance *this)
{
  this->mIsActive = 1;
}

// File Line: 55
// RVA: 0x1C8830
UFG::qColour *__fastcall Render::GeoInstance::ComputeColour(
        Render::GeoInstance *this,
        UFG::qColour *result,
        Render::GeoSettings *settings,
        float dTime)
{
  float v4; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm2_4
  float v8; // xmm3_4
  float a; // eax
  float v10; // xmm2_4
  float v11; // xmm0_4
  float v12; // xmm6_4
  float v13; // xmm7_4
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm7_4
  float v17; // xmm2_4
  float v18; // xmm4_4
  float v19; // xmm2_4
  float v20; // xmm0_4
  float v21; // xmm3_4
  UFG::qColour *v22; // rax

  v4 = settings->mColorKeyPositions[1];
  v5 = settings->mColorKeyPositions[2];
  v6 = settings->mColorKeyPositions[3];
  v8 = settings->mColorKeyPositions[0];
  if ( dTime >= v8 )
  {
    if ( dTime >= v4 )
    {
      if ( dTime >= v5 )
      {
        if ( dTime >= v6 )
        {
          result->r = settings->mColorAlphaKeys[3].r;
          result->g = settings->mColorAlphaKeys[3].g;
          result->b = settings->mColorAlphaKeys[3].b;
          a = settings->mColorAlphaKeys[3].a;
          goto LABEL_11;
        }
        v17 = (float)(dTime - v5) / (float)(v6 - v5);
        v11 = settings->mColorAlphaKeys[3].a;
        v12 = (float)(v17 * (float)(settings->mColorAlphaKeys[3].r - settings->mColorAlphaKeys[2].r))
            + settings->mColorAlphaKeys[2].r;
        v13 = (float)(v17 * (float)(settings->mColorAlphaKeys[3].b - settings->mColorAlphaKeys[2].b))
            + settings->mColorAlphaKeys[2].b;
        v14 = (float)(v17 * (float)(settings->mColorAlphaKeys[3].g - settings->mColorAlphaKeys[2].g))
            + settings->mColorAlphaKeys[2].g;
        v15 = settings->mColorAlphaKeys[2].a;
      }
      else
      {
        v16 = (float)(dTime - v4) / (float)(v5 - v4);
        v15 = settings->mColorAlphaKeys[1].a;
        v12 = (float)(v16 * (float)(settings->mColorAlphaKeys[2].r - settings->mColorAlphaKeys[1].r))
            + settings->mColorAlphaKeys[1].r;
        v14 = (float)(v16 * (float)(settings->mColorAlphaKeys[2].g - settings->mColorAlphaKeys[1].g))
            + settings->mColorAlphaKeys[1].g;
        v11 = settings->mColorAlphaKeys[2].a;
        v13 = (float)(v16 * (float)(settings->mColorAlphaKeys[2].b - settings->mColorAlphaKeys[1].b))
            + settings->mColorAlphaKeys[1].b;
      }
    }
    else
    {
      v10 = (float)(dTime - v8) / (float)(v4 - v8);
      v11 = settings->mColorAlphaKeys[1].a;
      v12 = (float)(v10 * (float)(settings->mColorAlphaKeys[1].r - settings->mColorAlphaKeys[0].r))
          + settings->mColorAlphaKeys[0].r;
      v13 = (float)(v10 * (float)(settings->mColorAlphaKeys[1].b - settings->mColorAlphaKeys[0].b))
          + settings->mColorAlphaKeys[0].b;
      v14 = (float)(v10 * (float)(settings->mColorAlphaKeys[1].g - settings->mColorAlphaKeys[0].g))
          + settings->mColorAlphaKeys[0].g;
      v15 = settings->mColorAlphaKeys[0].a;
    }
    result->r = v12;
    result->g = v14;
    result->b = v13;
    result->a = v15 + (float)(v11 - v15);
    goto LABEL_12;
  }
  result->r = settings->mColorAlphaKeys[0].r;
  result->g = settings->mColorAlphaKeys[0].g;
  result->b = settings->mColorAlphaKeys[0].b;
  a = settings->mColorAlphaKeys[0].a;
LABEL_11:
  result->a = a;
LABEL_12:
  v18 = settings->mAlphaKeyPositions[0];
  v19 = settings->mAlphaKeyPositions[1];
  v20 = settings->mAlphaKeyPositions[2];
  v21 = settings->mAlphaKeyPositions[3];
  if ( dTime >= v18 )
  {
    if ( dTime >= v19 )
    {
      if ( dTime >= v20 )
      {
        if ( dTime >= v21 )
        {
          result->a = settings->mColorAlphaKeys[3].a;
          return result;
        }
        else
        {
          v22 = result;
          result->a = (float)((float)((float)(dTime - v20) / (float)(v21 - v20))
                            * (float)(settings->mColorAlphaKeys[3].a - settings->mColorAlphaKeys[2].a))
                    + settings->mColorAlphaKeys[2].a;
        }
      }
      else
      {
        v22 = result;
        result->a = (float)((float)((float)(dTime - v19) / (float)(v20 - v19))
                          * (float)(settings->mColorAlphaKeys[2].a - settings->mColorAlphaKeys[1].a))
                  + settings->mColorAlphaKeys[1].a;
      }
    }
    else
    {
      v22 = result;
      result->a = (float)((float)((float)(dTime - v18) / (float)(v19 - v18))
                        * (float)(settings->mColorAlphaKeys[1].a - settings->mColorAlphaKeys[0].a))
                + settings->mColorAlphaKeys[0].a;
    }
  }
  else
  {
    result->a = settings->mColorAlphaKeys[0].a;
    return result;
  }
  return v22;
}

// File Line: 137
// RVA: 0x1C8F40
UFG::qVector3 *__fastcall Render::GeoInstance::ComputeSize(
        Render::GeoInstance *this,
        UFG::qVector3 *result,
        Render::GeoSettings *settings,
        float dTime)
{
  float v4; // xmm1_4
  UFG::qVector3 *v6; // rax
  float v7; // xmm0_4
  float v8; // xmm3_4
  float v9; // xmm6_4
  float v10; // xmm0_4
  float v11; // xmm4_4
  float v12; // xmm1_4
  float v13; // xmm3_4
  float v14; // xmm6_4
  float v15; // xmm0_4
  float v16; // xmm4_4
  float v17; // xmm0_4
  float z; // xmm3_4
  float v19; // xmm6_4
  float v20; // xmm0_4
  float v21; // xmm4_4

  v4 = settings->mSizeKeyPositions[0];
  if ( dTime >= v4 )
  {
    v7 = settings->mSizeKeyPositions[1];
    if ( dTime >= v7 )
    {
      v12 = settings->mSizeKeyPositions[2];
      if ( dTime >= v12 )
      {
        v17 = settings->mSizeKeyPositions[3];
        if ( dTime >= v17 )
        {
          *result = settings->mSizeKeys[3];
          return result;
        }
        else
        {
          z = settings->mSizeKeys[2].z;
          v6 = result;
          v19 = (float)(dTime - v12) / (float)(v17 - v12);
          v20 = (float)(settings->mSizeKeys[3].z - z) * v19;
          v21 = settings->mSizeKeys[2].y + (float)((float)(settings->mSizeKeys[3].y - settings->mSizeKeys[2].y) * v19);
          result->x = settings->mSizeKeys[2].x
                    + (float)((float)(settings->mSizeKeys[3].x - settings->mSizeKeys[2].x) * v19);
          result->y = v21;
          result->z = z + v20;
        }
      }
      else
      {
        v13 = settings->mSizeKeys[1].z;
        v6 = result;
        v14 = (float)(dTime - v7) / (float)(v12 - v7);
        v15 = (float)(settings->mSizeKeys[2].z - v13) * v14;
        v16 = settings->mSizeKeys[1].y + (float)((float)(settings->mSizeKeys[2].y - settings->mSizeKeys[1].y) * v14);
        result->x = settings->mSizeKeys[1].x
                  + (float)((float)(settings->mSizeKeys[2].x - settings->mSizeKeys[1].x) * v14);
        result->y = v16;
        result->z = v13 + v15;
      }
    }
    else
    {
      v8 = settings->mSizeKeys[0].z;
      v6 = result;
      v9 = (float)(dTime - v4) / (float)(v7 - v4);
      v10 = (float)(settings->mSizeKeys[1].z - v8) * v9;
      v11 = settings->mSizeKeys[0].y + (float)((float)(settings->mSizeKeys[1].y - settings->mSizeKeys[0].y) * v9);
      result->x = settings->mSizeKeys[0].x + (float)((float)(settings->mSizeKeys[1].x - settings->mSizeKeys[0].x) * v9);
      result->y = v11;
      result->z = v8 + v10;
    }
  }
  else
  {
    *result = settings->mSizeKeys[0];
    return result;
  }
  return v6;
}

// File Line: 165
// RVA: 0x1D9790
void __fastcall Render::GeoInstance::Update(Render::GeoInstance *this, UFG::qVector3 *cam_pos, float delta_sec)
{
  Render::GeoSettings *mData; // rsi
  Render::FXInstance *mContainer; // rax
  UFG::SimComponent *m_pPointer; // rdi
  UFG::qMatrix44 *p_mBasis; // rdx
  float v9; // xmm6_4
  float mFadeSpan; // xmm4_4
  __m128 x_low; // xmm2
  float v12; // xmm0_4
  UFG::qColour colorTint; // [rsp+30h] [rbp-F8h] BYREF
  UFG::qVector3 result; // [rsp+40h] [rbp-E8h] BYREF
  UFG::qMatrix44 dst; // [rsp+50h] [rbp-D8h] BYREF
  UFG::qMatrix44 dest; // [rsp+90h] [rbp-98h] BYREF
  UFG::qMatrix44 transform; // [rsp+D0h] [rbp-58h] BYREF

  mData = (Render::GeoSettings *)this->mSettingsHandle.mData;
  if ( this->mModelHandle.mData && mData )
  {
    mContainer = this->mContainer;
    m_pPointer = mContainer->mParentNode.m_pPointer;
    if ( !m_pPointer || mContainer->mBasisRelativeToParent )
    {
      p_mBasis = &mContainer->mBasis;
    }
    else
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)mContainer->mParentNode.m_pPointer);
      p_mBasis = (UFG::qMatrix44 *)&m_pPointer[2];
    }
    Render::FXInstance::CalcBasisHelper(
      &dst,
      p_mBasis,
      &this->mContainer->mSettings,
      this->mComponentIndex,
      this->mStartTime);
    v9 = (float)(delta_sec - this->mStartTime) / (float)(this->mEndTime - this->mStartTime);
    Render::GeoInstance::ComputeSize(this, &result, mData, v9);
    UFG::qScaleMatrix(&dest, &result);
    UFG::qMatrix44::operator*(&dest, &transform, &dst);
    Render::GeoInstance::ComputeColour(this, &colorTint, mData, v9);
    mFadeSpan = mData->mFadeSpan;
    if ( mFadeSpan > 0.0 )
    {
      x_low = (__m128)LODWORD(dst.v3.x);
      x_low.m128_f32[0] = (float)((float)((float)(dst.v3.x - cam_pos->x) * (float)(dst.v3.x - cam_pos->x))
                                + (float)((float)(dst.v3.y - cam_pos->y) * (float)(dst.v3.y - cam_pos->y)))
                        + (float)((float)(dst.v3.z - cam_pos->z) * (float)(dst.v3.z - cam_pos->z));
      v12 = (float)(_mm_sqrt_ps(x_low).m128_f32[0] - mData->mFadeDistance) / mFadeSpan;
      if ( v12 <= 0.0 )
      {
        v12 = 0.0;
      }
      else if ( v12 >= 1.0 )
      {
        v12 = *(float *)&FLOAT_1_0;
      }
      colorTint.a = colorTint.a * (float)(1.0 - v12);
    }
    Render::GeoManager::AddGeo(&Render::gGeoManager, &transform, &this->mModelHandle, &colorTint);
  }
}

