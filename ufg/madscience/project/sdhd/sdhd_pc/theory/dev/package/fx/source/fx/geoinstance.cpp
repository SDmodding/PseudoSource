// File Line: 13
// RVA: 0x1CEAE0
void __fastcall Render::GeoInstance::Init(Render::GeoInstance *this, unsigned int settingsId)
{
  UFG::qResourceInventory *v2; // rax
  unsigned int v3; // edi
  Render::GeoInstance *v4; // rbx
  UFG::qResourceWarehouse *v5; // rax
  UFG::qResourceData *v6; // rax
  unsigned int v7; // edi
  UFG::qResourceInventory *v8; // rax
  UFG::qResourceWarehouse *v9; // rax

  this->mSettingsId = settingsId;
  v2 = `UFG::qGetResourceInventory<Render::GeoSettings>::`2::result;
  v3 = settingsId;
  v4 = this;
  if ( !`UFG::qGetResourceInventory<Render::GeoSettings>::`2::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    v2 = UFG::qResourceWarehouse::GetInventory(v5, 0xF1734D8E);
    `UFG::qGetResourceInventory<Render::GeoSettings>::`2::result = v2;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v4->mSettingsHandle.mPrev, 0xF1734D8E, v3, v2);
  v6 = v4->mSettingsHandle.mData;
  if ( v6 )
  {
    v7 = *(_DWORD *)&v6[2].mDebugName[20];
    v8 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
    {
      v9 = UFG::qResourceWarehouse::Instance();
      v8 = UFG::qResourceWarehouse::GetInventory(v9, 0xA2ADCD77);
      `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v8;
    }
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v4->mModelHandle.mPrev, 0xA2ADCD77, v7, v8);
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
UFG::qColour *__fastcall Render::GeoInstance::ComputeColour(Render::GeoInstance *this, UFG::qColour *result, Render::GeoSettings *settings, float dTime)
{
  float v4; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm2_4
  float v7; // xmm8_4
  float v8; // xmm3_4
  float v9; // eax
  float v10; // xmm7_4
  float v11; // xmm2_4
  float v12; // xmm0_4
  float v13; // xmm6_4
  float v14; // xmm7_4
  float v15; // xmm2_4
  float v16; // xmm1_4
  float v17; // xmm7_4
  float v18; // xmm7_4
  float v19; // xmm2_4
  float v20; // xmm4_4
  float v21; // xmm2_4
  float v22; // xmm0_4
  float v23; // xmm3_4
  UFG::qColour *v24; // rax

  v4 = settings->mColorKeyPositions[1];
  v5 = settings->mColorKeyPositions[2];
  v6 = settings->mColorKeyPositions[3];
  v7 = dTime;
  v8 = settings->mColorKeyPositions[0];
  if ( v7 >= v8 )
  {
    if ( v7 >= v4 )
    {
      if ( v7 >= v5 )
      {
        if ( v7 >= v6 )
        {
          result->r = settings->mColorAlphaKeys[3].r;
          result->g = settings->mColorAlphaKeys[3].g;
          result->b = settings->mColorAlphaKeys[3].b;
          v9 = settings->mColorAlphaKeys[3].a;
          goto LABEL_11;
        }
        v18 = (float)(v7 - v5) / (float)(v6 - v5);
        v19 = v18;
        v12 = settings->mColorAlphaKeys[3].a;
        v13 = (float)(v18 * (float)(settings->mColorAlphaKeys[3].r - settings->mColorAlphaKeys[2].r))
            + settings->mColorAlphaKeys[2].r;
        v14 = (float)(v18 * (float)(settings->mColorAlphaKeys[3].b - settings->mColorAlphaKeys[2].b))
            + settings->mColorAlphaKeys[2].b;
        v15 = (float)(v19 * (float)(settings->mColorAlphaKeys[3].g - settings->mColorAlphaKeys[2].g))
            + settings->mColorAlphaKeys[2].g;
        v16 = settings->mColorAlphaKeys[2].a;
      }
      else
      {
        v17 = (float)(v7 - v4) / (float)(v5 - v4);
        v16 = settings->mColorAlphaKeys[1].a;
        v13 = (float)(v17 * (float)(settings->mColorAlphaKeys[2].r - settings->mColorAlphaKeys[1].r))
            + settings->mColorAlphaKeys[1].r;
        v15 = (float)(v17 * (float)(settings->mColorAlphaKeys[2].g - settings->mColorAlphaKeys[1].g))
            + settings->mColorAlphaKeys[1].g;
        v12 = settings->mColorAlphaKeys[2].a;
        v14 = (float)(v17 * (float)(settings->mColorAlphaKeys[2].b - settings->mColorAlphaKeys[1].b))
            + settings->mColorAlphaKeys[1].b;
      }
    }
    else
    {
      v10 = (float)(v7 - v8) / (float)(v4 - v8);
      v11 = v10;
      v12 = settings->mColorAlphaKeys[1].a;
      v13 = (float)(v10 * (float)(settings->mColorAlphaKeys[1].r - settings->mColorAlphaKeys[0].r))
          + settings->mColorAlphaKeys[0].r;
      v14 = (float)(v10 * (float)(settings->mColorAlphaKeys[1].b - settings->mColorAlphaKeys[0].b))
          + settings->mColorAlphaKeys[0].b;
      v15 = (float)(v11 * (float)(settings->mColorAlphaKeys[1].g - settings->mColorAlphaKeys[0].g))
          + settings->mColorAlphaKeys[0].g;
      v16 = settings->mColorAlphaKeys[0].a;
    }
    result->r = v13;
    result->g = v15;
    result->b = v14;
    result->a = v16 + (float)(v12 - v16);
    goto LABEL_12;
  }
  result->r = settings->mColorAlphaKeys[0].r;
  result->g = settings->mColorAlphaKeys[0].g;
  result->b = settings->mColorAlphaKeys[0].b;
  v9 = settings->mColorAlphaKeys[0].a;
LABEL_11:
  result->a = v9;
LABEL_12:
  v20 = settings->mAlphaKeyPositions[0];
  v21 = settings->mAlphaKeyPositions[1];
  v22 = settings->mAlphaKeyPositions[2];
  v23 = settings->mAlphaKeyPositions[3];
  if ( v7 >= v20 )
  {
    if ( v7 >= v21 )
    {
      if ( v7 >= v22 )
      {
        if ( v7 >= v23 )
        {
          result->a = settings->mColorAlphaKeys[3].a;
          v24 = result;
        }
        else
        {
          v24 = result;
          result->a = (float)((float)((float)(v7 - v22) / (float)(v23 - v22))
                            * (float)(settings->mColorAlphaKeys[3].a - settings->mColorAlphaKeys[2].a))
                    + settings->mColorAlphaKeys[2].a;
        }
      }
      else
      {
        v24 = result;
        result->a = (float)((float)((float)(v7 - v21) / (float)(v22 - v21))
                          * (float)(settings->mColorAlphaKeys[2].a - settings->mColorAlphaKeys[1].a))
                  + settings->mColorAlphaKeys[1].a;
      }
    }
    else
    {
      v24 = result;
      result->a = (float)((float)((float)(v7 - v20) / (float)(v21 - v20))
                        * (float)(settings->mColorAlphaKeys[1].a - settings->mColorAlphaKeys[0].a))
                + settings->mColorAlphaKeys[0].a;
    }
  }
  else
  {
    result->a = settings->mColorAlphaKeys[0].a;
    v24 = result;
  }
  return v24;
}

// File Line: 137
// RVA: 0x1C8F40
UFG::qVector3 *__fastcall Render::GeoInstance::ComputeSize(Render::GeoInstance *this, UFG::qVector3 *result, Render::GeoSettings *settings, float dTime)
{
  float v4; // xmm1_4
  float v5; // xmm6_4
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
  float v18; // xmm3_4
  float v19; // xmm6_4
  float v20; // xmm0_4
  float v21; // xmm4_4

  v4 = settings->mSizeKeyPositions[0];
  v5 = dTime;
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
          result->x = settings->mSizeKeys[3].x;
          result->y = settings->mSizeKeys[3].y;
          result->z = settings->mSizeKeys[3].z;
          v6 = result;
        }
        else
        {
          v18 = settings->mSizeKeys[2].z;
          v6 = result;
          v19 = (float)(v5 - v12) / (float)(v17 - v12);
          v20 = (float)(settings->mSizeKeys[3].z - v18) * v19;
          v21 = settings->mSizeKeys[2].y + (float)((float)(settings->mSizeKeys[3].y - settings->mSizeKeys[2].y) * v19);
          result->x = settings->mSizeKeys[2].x
                    + (float)((float)(settings->mSizeKeys[3].x - settings->mSizeKeys[2].x) * v19);
          result->y = v21;
          result->z = v18 + v20;
        }
      }
      else
      {
        v13 = settings->mSizeKeys[1].z;
        v6 = result;
        v14 = (float)(v5 - v7) / (float)(v12 - v7);
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
      v9 = (float)(v5 - v4) / (float)(v7 - v4);
      v10 = (float)(settings->mSizeKeys[1].z - v8) * v9;
      v11 = settings->mSizeKeys[0].y + (float)((float)(settings->mSizeKeys[1].y - settings->mSizeKeys[0].y) * v9);
      result->x = settings->mSizeKeys[0].x + (float)((float)(settings->mSizeKeys[1].x - settings->mSizeKeys[0].x) * v9);
      result->y = v11;
      result->z = v8 + v10;
    }
  }
  else
  {
    result->x = settings->mSizeKeys[0].x;
    result->y = settings->mSizeKeys[0].y;
    result->z = settings->mSizeKeys[0].z;
    v6 = result;
  }
  return v6;
}

// File Line: 165
// RVA: 0x1D9790
void __fastcall Render::GeoInstance::Update(Render::GeoInstance *this, UFG::qVector3 *cam_pos, float delta_sec)
{
  Render::GeoSettings *v3; // rsi
  UFG::qVector3 *v4; // rbp
  Render::GeoInstance *v5; // rbx
  Render::FXInstance *v6; // rax
  UFG::SimComponent *v7; // rdi
  UFG::qMatrix44 *v8; // rdx
  float v9; // xmm6_4
  float v10; // xmm4_4
  __m128 v11; // xmm2
  float v12; // xmm0_4
  UFG::qColour colorTint; // [rsp+30h] [rbp-F8h]
  UFG::qVector3 result; // [rsp+40h] [rbp-E8h]
  UFG::qMatrix44 dst; // [rsp+50h] [rbp-D8h]
  UFG::qMatrix44 dest; // [rsp+90h] [rbp-98h]
  UFG::qMatrix44 transform; // [rsp+D0h] [rbp-58h]

  v3 = (Render::GeoSettings *)this->mSettingsHandle.mData;
  v4 = cam_pos;
  v5 = this;
  if ( this->mModelHandle.mData && v3 )
  {
    v6 = this->mContainer;
    v7 = v6->mParentNode.m_pPointer;
    if ( !v7 || v6->mBasisRelativeToParent )
    {
      v8 = &v6->mBasis;
    }
    else
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v6->mParentNode.m_pPointer);
      v8 = (UFG::qMatrix44 *)&v7[2];
    }
    Render::FXInstance::CalcBasisHelper(
      &dst,
      v8,
      (UFG::qResourceHandle *)&v5->mContainer->mSettings.mPrev,
      v5->mComponentIndex,
      v5->mStartTime);
    v9 = (float)(delta_sec - v5->mStartTime) / (float)(v5->mEndTime - v5->mStartTime);
    Render::GeoInstance::ComputeSize(v5, &result, v3, v9);
    UFG::qScaleMatrix(&dest, &result);
    UFG::qMatrix44::operator*(&dest, &transform, &dst);
    Render::GeoInstance::ComputeColour(v5, &colorTint, v3, v9);
    v10 = v3->mFadeSpan;
    if ( v10 > 0.0 )
    {
      v11 = (__m128)LODWORD(dst.v3.x);
      v11.m128_f32[0] = (float)((float)((float)(dst.v3.x - v4->x) * (float)(dst.v3.x - v4->x))
                              + (float)((float)(dst.v3.y - v4->y) * (float)(dst.v3.y - v4->y)))
                      + (float)((float)(dst.v3.z - v4->z) * (float)(dst.v3.z - v4->z));
      v12 = (float)(COERCE_FLOAT(_mm_sqrt_ps(v11)) - v3->mFadeDistance) / v10;
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
    Render::GeoManager::AddGeo(&Render::gGeoManager, &transform, &v5->mModelHandle, &colorTint);
  }
}

