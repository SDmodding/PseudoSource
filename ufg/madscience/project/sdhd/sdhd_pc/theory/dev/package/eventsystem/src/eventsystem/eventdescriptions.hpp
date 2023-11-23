// File Line: 55
// RVA: 0x4CBA90
void __fastcall UFG::TeleportEvent::TeleportEvent(
        UFG::TeleportEvent *this,
        unsigned int uidSimObject,
        unsigned int uidXForm,
        const char *pName)
{
  unsigned int v4; // r10d
  float y; // xmm1_4
  float z; // xmm2_4
  float w; // xmm3_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm3_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm3_4

  v4 = UFG::TeleportEvent::EVENT_UID;
  this->mPrev = &this->UFG::qNode<UFG::Event,UFG::Event>;
  this->mNext = &this->UFG::qNode<UFG::Event,UFG::Event>;
  this->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
  this->m_EventUID = v4;
  this->m_NamePTR = pName;
  this->vfptr = (UFG::EventVtbl *)&UFG::TeleportEvent::`vftable;
  this->mSimObjectUID = uidSimObject;
  this->mXFormComponentUID = uidXForm;
  this->mLocalOnly = 0;
  y = UFG::qMatrix44::msIdentity.v0.y;
  z = UFG::qMatrix44::msIdentity.v0.z;
  w = UFG::qMatrix44::msIdentity.v0.w;
  this->m_Xform.v0.x = UFG::qMatrix44::msIdentity.v0.x;
  this->m_Xform.v0.y = y;
  this->m_Xform.v0.z = z;
  this->m_Xform.v0.w = w;
  v8 = UFG::qMatrix44::msIdentity.v1.y;
  v9 = UFG::qMatrix44::msIdentity.v1.z;
  v10 = UFG::qMatrix44::msIdentity.v1.w;
  this->m_Xform.v1.x = UFG::qMatrix44::msIdentity.v1.x;
  this->m_Xform.v1.y = v8;
  this->m_Xform.v1.z = v9;
  this->m_Xform.v1.w = v10;
  v11 = UFG::qMatrix44::msIdentity.v2.y;
  v12 = UFG::qMatrix44::msIdentity.v2.z;
  v13 = UFG::qMatrix44::msIdentity.v2.w;
  this->m_Xform.v2.x = UFG::qMatrix44::msIdentity.v2.x;
  this->m_Xform.v2.y = v11;
  this->m_Xform.v2.z = v12;
  this->m_Xform.v2.w = v13;
  v14 = UFG::qMatrix44::msIdentity.v3.y;
  v15 = UFG::qMatrix44::msIdentity.v3.z;
  v16 = UFG::qMatrix44::msIdentity.v3.w;
  this->m_Xform.v3.x = UFG::qMatrix44::msIdentity.v3.x;
  this->m_Xform.v3.y = v14;
  this->m_Xform.v3.z = v15;
  this->m_Xform.v3.w = v16;
}

// File Line: 62
// RVA: 0x202A60
void __fastcall UFG::TeleportEvent::TeleportEvent(
        UFG::TeleportEvent *this,
        UFG::qMatrix44 *worldXform,
        unsigned int uidSimObject,
        unsigned int uidXForm,
        const char *pName,
        bool localOnly)
{
  unsigned int v6; // r10d
  float y; // xmm1_4
  float z; // xmm2_4
  float w; // xmm3_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm3_4

  v6 = UFG::TeleportEvent::EVENT_UID;
  this->mPrev = &this->UFG::qNode<UFG::Event,UFG::Event>;
  this->mNext = &this->UFG::qNode<UFG::Event,UFG::Event>;
  this->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
  this->m_EventUID = v6;
  this->m_NamePTR = pName;
  this->vfptr = (UFG::EventVtbl *)&UFG::TeleportEvent::`vftable;
  this->mSimObjectUID = uidSimObject;
  this->mXFormComponentUID = uidXForm;
  this->mLocalOnly = localOnly;
  y = worldXform->v0.y;
  z = worldXform->v0.z;
  w = worldXform->v0.w;
  this->m_Xform.v0.x = worldXform->v0.x;
  this->m_Xform.v0.y = y;
  this->m_Xform.v0.z = z;
  this->m_Xform.v0.w = w;
  v10 = worldXform->v1.y;
  v11 = worldXform->v1.z;
  v12 = worldXform->v1.w;
  this->m_Xform.v1.x = worldXform->v1.x;
  this->m_Xform.v1.y = v10;
  this->m_Xform.v1.z = v11;
  this->m_Xform.v1.w = v12;
  v13 = worldXform->v2.y;
  v14 = worldXform->v2.z;
  v15 = worldXform->v2.w;
  this->m_Xform.v2.x = worldXform->v2.x;
  this->m_Xform.v2.y = v13;
  this->m_Xform.v2.z = v14;
  this->m_Xform.v2.w = v15;
  v16 = worldXform->v3.y;
  v17 = worldXform->v3.z;
  v18 = worldXform->v3.w;
  this->m_Xform.v3.x = worldXform->v3.x;
  this->m_Xform.v3.y = v16;
  this->m_Xform.v3.z = v17;
  this->m_Xform.v3.w = v18;
}

// File Line: 69
// RVA: 0x405620
void __fastcall UFG::TeleportEvent::TeleportEvent(
        UFG::TeleportEvent *this,
        UFG::qVector3 *position,
        unsigned int uidSimObject,
        unsigned int uidXForm,
        const char *pName,
        bool localOnly)
{
  unsigned int v6; // r10d

  v6 = UFG::TeleportEvent::EVENT_UID;
  this->mPrev = &this->UFG::qNode<UFG::Event,UFG::Event>;
  this->mNext = &this->UFG::qNode<UFG::Event,UFG::Event>;
  this->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
  this->m_EventUID = v6;
  this->m_NamePTR = pName;
  this->vfptr = (UFG::EventVtbl *)&UFG::TeleportEvent::`vftable;
  this->mSimObjectUID = uidSimObject;
  this->mXFormComponentUID = uidXForm;
  this->mLocalOnly = localOnly;
  UFG::qTranslationMatrix(&this->m_Xform, position);
}

// File Line: 85
// RVA: 0x1B9DE0
void __fastcall UFG::TeleportEvent::TeleportEvent(
        UFG::TeleportEvent *this,
        UFG::qVector3 *origin,
        UFG::qVector3 *dir,
        unsigned int uidSimObject,
        unsigned int uidXForm,
        const char *pName,
        UFG::qVector3 *upDir)
{
  unsigned int v7; // r10d
  float y; // xmm7_4
  __m128 x_low; // xmm8
  __m128 z_low; // xmm6
  __m128 v11; // xmm2
  float v12; // xmm1_4
  float v13; // xmm6_4
  float v14; // xmm7_4
  float v15; // xmm8_4
  __m128 y_low; // xmm5
  __m128 v17; // xmm10
  float z; // xmm9_4
  __m128 v19; // xmm2
  float v20; // xmm1_4
  float v21; // xmm9_4
  float v22; // xmm10_4
  float v23; // xmm11_4
  float v24; // xmm12_4
  __m128 v25; // xmm2
  float v26; // xmm1_4
  float v27; // xmm11_4
  float v28; // xmm12_4
  float v29; // xmm5_4
  float v30; // xmm7_4
  float v31; // xmm8_4
  __m128 v32; // xmm5
  float v33; // xmm3_4
  float v34; // xmm1_4
  float v35; // xmm2_4

  v7 = UFG::TeleportEvent::EVENT_UID;
  this->mPrev = &this->UFG::qNode<UFG::Event,UFG::Event>;
  this->mNext = &this->UFG::qNode<UFG::Event,UFG::Event>;
  this->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
  this->m_EventUID = v7;
  this->m_NamePTR = pName;
  this->vfptr = (UFG::EventVtbl *)&UFG::TeleportEvent::`vftable;
  this->mSimObjectUID = uidSimObject;
  this->mXFormComponentUID = uidXForm;
  this->mLocalOnly = 0;
  y = dir->y;
  x_low = (__m128)LODWORD(dir->x);
  z_low = (__m128)LODWORD(dir->z);
  v11 = x_low;
  v11.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(y * y))
                  + (float)(z_low.m128_f32[0] * z_low.m128_f32[0]);
  if ( v11.m128_f32[0] == 0.0 )
    v12 = 0.0;
  else
    v12 = 1.0 / _mm_sqrt_ps(v11).m128_f32[0];
  v13 = z_low.m128_f32[0] * v12;
  v14 = y * v12;
  v15 = x_low.m128_f32[0] * v12;
  this->m_Xform.v0.x = v15;
  this->m_Xform.v0.y = v14;
  this->m_Xform.v0.z = v13;
  this->m_Xform.v0.w = 0.0;
  y_low = (__m128)LODWORD(upDir->y);
  v17 = (__m128)LODWORD(upDir->x);
  z = upDir->z;
  v19 = v17;
  v19.m128_f32[0] = (float)((float)(v17.m128_f32[0] * v17.m128_f32[0]) + (float)(y_low.m128_f32[0] * y_low.m128_f32[0]))
                  + (float)(z * z);
  if ( v19.m128_f32[0] == 0.0 )
    v20 = 0.0;
  else
    v20 = 1.0 / _mm_sqrt_ps(v19).m128_f32[0];
  v21 = z * v20;
  y_low.m128_f32[0] = y_low.m128_f32[0] * v20;
  v22 = v17.m128_f32[0] * v20;
  v23 = (float)(v22 * v14) - (float)(y_low.m128_f32[0] * v15);
  v24 = (float)(v21 * v15) - (float)(v22 * v13);
  y_low.m128_f32[0] = (float)(y_low.m128_f32[0] * v13) - (float)(v21 * v14);
  v25 = y_low;
  v25.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v24 * v24)) + (float)(v23 * v23);
  if ( v25.m128_f32[0] == 0.0 )
    v26 = 0.0;
  else
    v26 = 1.0 / _mm_sqrt_ps(v25).m128_f32[0];
  v27 = v23 * v26;
  v28 = v24 * v26;
  v29 = y_low.m128_f32[0] * v26;
  this->m_Xform.v1.x = v29;
  this->m_Xform.v1.y = v28;
  this->m_Xform.v1.z = v27;
  this->m_Xform.v1.w = 0.0;
  z_low.m128_f32[0] = v14;
  v30 = (float)(v15 * v28) - (float)(v14 * v29);
  v31 = (float)(this->m_Xform.v0.z * v29) - (float)(v15 * v27);
  z_low.m128_f32[0] = (float)(z_low.m128_f32[0] * v27) - (float)(this->m_Xform.v0.z * v28);
  v32 = z_low;
  v32.m128_f32[0] = (float)((float)(z_low.m128_f32[0] * z_low.m128_f32[0]) + (float)(v31 * v31)) + (float)(v30 * v30);
  if ( v32.m128_f32[0] == 0.0 )
    v33 = 0.0;
  else
    v33 = 1.0 / _mm_sqrt_ps(v32).m128_f32[0];
  this->m_Xform.v2.x = v33 * z_low.m128_f32[0];
  this->m_Xform.v2.y = v33 * v31;
  this->m_Xform.v2.z = v33 * v30;
  this->m_Xform.v2.w = 0.0;
  v34 = origin->y;
  v35 = origin->z;
  this->m_Xform.v3.x = origin->x;
  this->m_Xform.v3.y = v34;
  this->m_Xform.v3.z = v35;
  this->m_Xform.v3.w = 1.0;
}

// File Line: 254
// RVA: 0xA3AA20
void __fastcall UFG::UIMouseEvent::UIMouseEvent(UFG::UIMouseEvent *this, const char *name)
{
  this->mPrev = &this->UFG::qNode<UFG::Event,UFG::Event>;
  this->mNext = &this->UFG::qNode<UFG::Event,UFG::Event>;
  this->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
  this->m_NamePTR = name;
  this->m_EventUID = UFG::qStringHash32(name, 0xFFFFFFFF);
  this->vfptr = (UFG::EventVtbl *)&UFG::UIMouseEvent::`vftable;
  *(_QWORD *)&this->winMsg = 0i64;
  *(_QWORD *)&this->mouseY = 0i64;
  this->mouseWheel = 0;
}

