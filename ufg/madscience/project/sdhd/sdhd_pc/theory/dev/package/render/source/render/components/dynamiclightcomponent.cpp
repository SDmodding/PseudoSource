// File Line: 15
// RVA: 0x14572D0
__int64 dynamic_initializer_for__Render::DynamicLightComponent::s_DynamicLightComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__Render::DynamicLightComponent::s_DynamicLightComponentList__);
}

// File Line: 16
// RVA: 0x73070
const char *__fastcall Render::DynamicLightComponent::GetTypeName(Render::DynamicLightComponent *this)
{
  return "DynamicLightComponent";
}

// File Line: 20
// RVA: 0x72EC0
void __fastcall Render::DynamicLightComponent::DynamicLightComponent(Render::DynamicLightComponent *this, unsigned int nameUID)
{
  Render::DynamicLightComponent *v2; // rbx
  UFG::qNode<Render::DynamicLightComponent,Render::DynamicLightComponent> *v3; // rdx
  UFG::qNode<Render::DynamicLightComponent,Render::DynamicLightComponent> *v4; // rax

  v2 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, nameUID);
  v3 = (UFG::qNode<Render::DynamicLightComponent,Render::DynamicLightComponent> *)&v2->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&Render::DynamicLightComponent::`vftable';
  v4 = Render::DynamicLightComponent::s_DynamicLightComponentList.mNode.mPrev;
  Render::DynamicLightComponent::s_DynamicLightComponentList.mNode.mPrev->mNext = (UFG::qNode<Render::DynamicLightComponent,Render::DynamicLightComponent> *)&v2->mPrev;
  v3->mPrev = v4;
  v2->mNext = (UFG::qNode<Render::DynamicLightComponent,Render::DynamicLightComponent> *)&Render::DynamicLightComponent::s_DynamicLightComponentList;
  Render::DynamicLightComponent::s_DynamicLightComponentList.mNode.mPrev = (UFG::qNode<Render::DynamicLightComponent,Render::DynamicLightComponent> *)&v2->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v2->vfptr,
    Render::DynamicLightComponent::_DynamicLightComponentTypeUID,
    "DynamicLightComponent");
}

// File Line: 26
// RVA: 0x72F30
void __fastcall Render::DynamicLightComponent::~DynamicLightComponent(Render::DynamicLightComponent *this)
{
  Render::DynamicLightComponent *v1; // r8
  UFG::qNode<Render::DynamicLightComponent,Render::DynamicLightComponent> *v2; // rdx
  UFG::qNode<Render::DynamicLightComponent,Render::DynamicLightComponent> *v3; // rcx
  UFG::qNode<Render::DynamicLightComponent,Render::DynamicLightComponent> *v4; // rax
  UFG::qNode<Render::DynamicLightComponent,Render::DynamicLightComponent> *v5; // rcx
  UFG::qNode<Render::DynamicLightComponent,Render::DynamicLightComponent> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&Render::DynamicLightComponent::`vftable';
  if ( this == Render::DynamicLightComponent::s_DynamicLightComponentpCurrentIterator )
    Render::DynamicLightComponent::s_DynamicLightComponentpCurrentIterator = (Render::DynamicLightComponent *)&this->mPrev[-4];
  v2 = (UFG::qNode<Render::DynamicLightComponent,Render::DynamicLightComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 31
// RVA: 0x73080
Render::DynamicLightComponent *__fastcall Render::DynamicLightComponent::PropertiesOnActivate(UFG::SceneObjectProperties *sceneObj)
{
  UFG::SceneObjectProperties *v1; // rbx
  UFG::SimObject *v2; // rbp
  UFG::qMemoryPool *v3; // rax
  char *v4; // rax
  __int64 v5; // rax
  __int64 v6; // rdi
  UFG::qPropertySet *v7; // rcx
  UFG::qPropertySet *v8; // rax
  char *v9; // rsi
  UFG::TransformNodeComponent *v10; // rbx
  UFG::qVector4 v11; // xmm1
  UFG::qVector4 v12; // xmm2
  UFG::qVector4 v13; // xmm3
  float v14; // xmm0_4
  int v15; // eax
  float v16; // xmm9_4
  float v17; // xmm0_4
  float v18; // xmm7_4
  __m128 v19; // xmm1
  float v20; // xmm10_4
  float v21; // xmm0_4
  float v22; // xmm7_4
  float v23; // xmm6_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  float v26; // xmm2_4
  float v27; // xmm10_4
  float v28; // xmm12_4
  float v29; // xmm14_4
  int v30; // xmm11_4
  int v31; // xmm13_4
  __m128 v32; // xmm7
  float v33; // xmm2_4
  float v34; // xmm1_4
  float v35; // xmm4_4
  float v36; // xmm5_4
  float v37; // xmm10_4
  float v38; // xmm1_4
  __m128 v39; // xmm2
  __m128 v40; // xmm15
  float v41; // xmm13_4
  float v42; // xmm3_4
  __m128 v43; // xmm1
  float v44; // xmm1_4
  float v45; // xmm1_4
  float v46; // xmm2_4
  float v47; // xmm11_4
  float v48; // xmm6_4
  float v49; // xmm14_4
  __m128 v50; // xmm2
  float v51; // xmm1_4
  float v52; // xmm14_4
  float v53; // xmm2_4
  float v54; // xmm10_4
  float v55; // xmm14_4
  __m128 v56; // xmm3
  float v57; // xmm1_4
  float v58; // xmm14_4
  float v59; // xmm2_4
  float v60; // xmm10_4
  float v61; // xmm13_4
  float v62; // xmm2_4
  float v63; // xmm1_4
  float v64; // xmm13_4
  float v65; // xmm2_4
  float v66; // xmm10_4
  float v67; // xmm13_4
  __m128 v68; // xmm2
  float v69; // xmm1_4
  float v70; // xmm13_4
  float v71; // xmm6_4
  float v72; // xmm10_4
  float v73; // xmm11_4
  float v74; // xmm6_4
  float v75; // xmm7_4
  float v76; // xmm1_4
  float v78; // [rsp+30h] [rbp-108h]
  float v79; // [rsp+34h] [rbp-104h]
  float v80; // [rsp+38h] [rbp-100h]
  float v81; // [rsp+3Ch] [rbp-FCh]
  UFG::SimObjectModifier v82; // [rsp+48h] [rbp-F0h]
  float v83; // [rsp+140h] [rbp+8h]
  float v84; // [rsp+148h] [rbp+10h]
  float v85; // [rsp+150h] [rbp+18h]
  float v86; // [rsp+158h] [rbp+20h]

  v1 = sceneObj;
  v2 = sceneObj->m_pSimObject;
  v3 = UFG::GetSimulationMemoryPool();
  v4 = UFG::qMemoryPool::Allocate(v3, 0xF0ui64, "DynamicLightComponent", 0i64, 1u);
  if ( v4 )
  {
    Render::DynamicLightComponent::DynamicLightComponent((Render::DynamicLightComponent *)v4, v1->m_NameUID);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v82, v2, 1);
  UFG::SimObjectModifier::AttachComponent(&v82, (UFG::SimComponent *)v6, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v82);
  UFG::SimObjectModifier::~SimObjectModifier(&v82);
  v7 = v1->mpWritableProperties;
  if ( !v7 )
    v7 = v1->mpConstProperties;
  v8 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v7,
         (UFG::qSymbol *)&component_DynamicLight::sPropertyName.mUID,
         DEPTH_RECURSE);
  if ( v8 )
    v9 = UFG::qPropertySet::GetMemImagePtr(v8);
  else
    v9 = 0i64;
  *(_DWORD *)(v6 + 204) = v2->mNode.mUID;
  v10 = v2->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(v2->m_pTransformNodeComponent);
  v11 = v10->mWorldTransform.v1;
  v12 = v10->mWorldTransform.v2;
  v13 = v10->mWorldTransform.v3;
  *(UFG::qVector4 *)(v6 + 80) = v10->mWorldTransform.v0;
  *(UFG::qVector4 *)(v6 + 96) = v11;
  *(UFG::qVector4 *)(v6 + 112) = v12;
  *(UFG::qVector4 *)(v6 + 128) = v13;
  v14 = *((float *)v9 + 3) * *((float *)v9 + 1);
  v12.x = *((float *)v9 + 3) * *((float *)v9 + 2);
  *(float *)(v6 + 144) = *((float *)v9 + 3) * *(float *)v9;
  *(float *)(v6 + 148) = v14;
  *(float *)(v6 + 152) = v12.x;
  *(_DWORD *)(v6 + 156) = *((_DWORD *)v9 + 5);
  *(float *)(v6 + 176) = *((float *)v9 + 13) * 3600.0;
  *(float *)(v6 + 180) = *((float *)v9 + 14) * 3600.0;
  *(_BYTE *)(v6 + 184) = v9[76];
  *(_DWORD *)(v6 + 192) = *((_DWORD *)v9 + 4);
  *(_BYTE *)(v6 + 186) = v9[72];
  *(_DWORD *)(v6 + 168) = *((_DWORD *)v9 + 8);
  *(_DWORD *)(v6 + 172) = *((_DWORD *)v9 + 15);
  v15 = *((_DWORD *)v9 + 16);
  *(_DWORD *)(v6 + 228) = v15;
  v16 = *(float *)&FLOAT_1_0;
  if ( v15 == -1 )
  {
    *(_DWORD *)(v6 + 232) = -1082130432;
  }
  else
  {
    v17 = (float)(*((float *)v9 + 17) + 0.5) * 0.0078125;
    if ( v17 <= 0.0 )
    {
      v17 = 0.0;
    }
    else if ( v17 >= 1.0 )
    {
      v17 = *(float *)&FLOAT_1_0;
    }
    *(float *)(v6 + 232) = v17;
    *(_DWORD *)(v6 + 192) = 0;
  }
  *(float *)(v6 + 160) = (float)((float)(*((float *)v9 + 6) * 0.5) * 3.1415927) * 0.0055555557;
  *(float *)(v6 + 164) = (float)((float)(*((float *)v9 + 7) * 0.5) * 3.1415927) * 0.0055555557;
  *(_BYTE *)(v6 + 187) = 0;
  *(_BYTE *)(v6 + 185) = -(v9[73] != 0);
  if ( *(_BYTE *)(v6 + 184) != 5 )
  {
    *(_QWORD *)(v6 + 208) = 0i64;
    *(_QWORD *)(v6 + 216) = 0i64;
    *(_DWORD *)(v6 + 224) = 0;
    return (Render::DynamicLightComponent *)v6;
  }
  v18 = *((float *)v9 + 9);
  if ( v18 <= 0.0 )
    v18 = 0.0;
  *(float *)(v6 + 208) = v18;
  v19 = (__m128)*((unsigned int *)v9 + 10);
  if ( v19.m128_f32[0] <= 0.0 )
    v19 = 0i64;
  *(_DWORD *)(v6 + 212) = v19.m128_i32[0];
  v20 = *((float *)v9 + 11);
  if ( v20 <= 0.0 )
    v20 = 0.0;
  *(float *)(v6 + 216) = v20;
  v21 = *((float *)v9 + 12);
  if ( v21 <= 0.0 )
    v21 = 0.0;
  *(float *)(v6 + 220) = v21;
  if ( v21 < 0.000099999997 )
    *(_DWORD *)(v6 + 220) = 1148846080;
  if ( v20 <= 0.0099999998 )
  {
    *(_DWORD *)(v6 + 164) = 1070009624;
    *(_DWORD *)(v6 + 160) = 1070009624;
  }
  else
  {
    v22 = v18 * 0.5;
    v23 = 1.0 / (float)(v20 * 0.5);
    v19.m128_f32[0] = (float)((float)(v19.m128_f32[0] * 0.5) * (float)(v19.m128_f32[0] * 0.5)) + (float)(v22 * v22);
    *(float *)(v6 + 164) = atanf(COERCE_FLOAT(_mm_sqrt_ps(v19)) * v23);
    *(float *)(v6 + 160) = atanf(v23 * v22);
  }
  *(float *)(v6 + 156) = (float)(v20 * 0.5) + *(float *)(v6 + 156);
  v24 = v20 * *(float *)(v6 + 112);
  v25 = v20 * *(float *)(v6 + 116);
  v26 = v20 * *(float *)(v6 + 120);
  v27 = (float)(v20 * *(float *)(v6 + 124)) * 0.5;
  *(float *)(v6 + 128) = (float)(v24 * 0.5) + *(float *)(v6 + 128);
  *(float *)(v6 + 132) = (float)(v25 * 0.5) + *(float *)(v6 + 132);
  *(float *)(v6 + 136) = (float)(v26 * 0.5) + *(float *)(v6 + 136);
  *(float *)(v6 + 140) = v27 + *(float *)(v6 + 140);
  v81 = *((float *)v9 + 3);
  v28 = *(float *)(v6 + 208) * 0.5;
  v29 = *(float *)(v6 + 212) * 0.5;
  v30 = LODWORD(v28) ^ _xmm[0];
  v31 = LODWORD(v29) ^ _xmm[0];
  v32 = (__m128)*(unsigned int *)(v6 + 216);
  v32.m128_f32[0] = v32.m128_f32[0] + 0.001;
  v33 = (float)((float)(*(float *)&v31 * *(float *)&v31) + (float)(*(float *)&v30 * *(float *)&v30))
      + (float)(v32.m128_f32[0] * v32.m128_f32[0]);
  if ( v33 == 0.0 )
    v34 = 0.0;
  else
    v34 = 1.0 / fsqrt(v33);
  v35 = *(float *)&v30 * v34;
  v80 = *(float *)&v30 * v34;
  v36 = *(float *)&v31 * v34;
  v79 = *(float *)&v31 * v34;
  v37 = v32.m128_f32[0] * v34;
  v78 = v32.m128_f32[0] * v34;
  v38 = (float)((float)(*(float *)&v31 * *(float *)&v31) + (float)(v28 * v28))
      + (float)(v32.m128_f32[0] * v32.m128_f32[0]);
  if ( v38 == 0.0 )
  {
    v39 = 0i64;
  }
  else
  {
    v39 = (__m128)(unsigned int)FLOAT_1_0;
    v39.m128_f32[0] = 1.0 / fsqrt(v38);
  }
  v40 = v39;
  v40.m128_f32[0] = v39.m128_f32[0] * v28;
  v41 = *(float *)&v31 * v39.m128_f32[0];
  v42 = v32.m128_f32[0] * v39.m128_f32[0];
  v86 = v32.m128_f32[0] * v39.m128_f32[0];
  v43 = v32;
  v43.m128_f32[0] = (float)(v32.m128_f32[0] * v32.m128_f32[0]) + (float)((float)(v29 * v29) + (float)(v28 * v28));
  if ( v43.m128_f32[0] == 0.0 )
    v44 = 0.0;
  else
    v44 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v43));
  v85 = v44 * v28;
  v83 = v44 * v29;
  v84 = v32.m128_f32[0] * v44;
  v45 = (float)((float)(*(float *)&v30 * *(float *)&v30) + (float)(v29 * v29))
      + (float)(v32.m128_f32[0] * v32.m128_f32[0]);
  if ( v45 == 0.0 )
    v46 = 0.0;
  else
    v46 = 1.0 / fsqrt(v45);
  v47 = *(float *)&v30 * v46;
  v48 = v46 * v29;
  v32.m128_f32[0] = v32.m128_f32[0] * v46;
  v50 = v40;
  v49 = (float)(v41 * v35) - (float)(v40.m128_f32[0] * v36);
  v50.m128_f32[0] = (float)((float)((float)((float)(v40.m128_f32[0] * v37) - (float)(v42 * v35))
                                  * (float)((float)(v40.m128_f32[0] * v37) - (float)(v42 * v35)))
                          + (float)((float)((float)(v42 * v36) - (float)(v41 * v37))
                                  * (float)((float)(v42 * v36) - (float)(v41 * v37))))
                  + (float)(v49 * v49);
  if ( v50.m128_f32[0] == 0.0 )
    v51 = 0.0;
  else
    v51 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v50));
  v52 = v49 * v51;
  v53 = (float)((float)(v41 * v36) + (float)(v40.m128_f32[0] * v35)) + (float)(v42 * v37);
  if ( v53 <= -1.0 )
  {
    v53 = FLOAT_N1_0;
  }
  else if ( v53 >= 1.0 )
  {
    v53 = *(float *)&FLOAT_1_0;
  }
  v54 = acosf(v53) * v52;
  v56 = (__m128)LODWORD(v85);
  v55 = (float)(v83 * v40.m128_f32[0]) - (float)(v85 * v41);
  v56.m128_f32[0] = (float)((float)((float)((float)(v85 * v86) - (float)(v84 * v40.m128_f32[0]))
                                  * (float)((float)(v85 * v86) - (float)(v84 * v40.m128_f32[0])))
                          + (float)((float)((float)(v84 * v41) - (float)(v83 * v86))
                                  * (float)((float)(v84 * v41) - (float)(v83 * v86))))
                  + (float)(v55 * v55);
  if ( v56.m128_f32[0] == 0.0 )
    v57 = 0.0;
  else
    v57 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v56));
  v58 = v55 * v57;
  v59 = (float)((float)(v83 * v41) + (float)(v85 * v40.m128_f32[0])) + (float)(v84 * v86);
  if ( v59 <= -1.0 )
  {
    v59 = FLOAT_N1_0;
  }
  else if ( v59 >= 1.0 )
  {
    v59 = *(float *)&FLOAT_1_0;
  }
  v60 = v54 + (float)(acosf(v59) * v58);
  v61 = (float)(v48 * v85) - (float)(v47 * v83);
  v62 = (float)((float)((float)((float)(v47 * v84) - (float)(v32.m128_f32[0] * v85))
                      * (float)((float)(v47 * v84) - (float)(v32.m128_f32[0] * v85)))
              + (float)((float)((float)(v32.m128_f32[0] * v83) - (float)(v48 * v84))
                      * (float)((float)(v32.m128_f32[0] * v83) - (float)(v48 * v84))))
      + (float)(v61 * v61);
  if ( v62 == 0.0 )
    v63 = 0.0;
  else
    v63 = 1.0 / fsqrt(v62);
  v64 = v61 * v63;
  v65 = (float)((float)(v48 * v83) + (float)(v47 * v85)) + (float)(v32.m128_f32[0] * v84);
  if ( v65 <= -1.0 )
  {
    v65 = FLOAT_N1_0;
  }
  else if ( v65 >= 1.0 )
  {
    v65 = *(float *)&FLOAT_1_0;
  }
  v66 = v60 + (float)(acosf(v65) * v64);
  v68 = v32;
  v67 = (float)(v47 * v79) - (float)(v48 * v80);
  v68.m128_f32[0] = (float)((float)((float)((float)(v32.m128_f32[0] * v80) - (float)(v47 * v78))
                                  * (float)((float)(v32.m128_f32[0] * v80) - (float)(v47 * v78)))
                          + (float)((float)((float)(v48 * v78) - (float)(v32.m128_f32[0] * v79))
                                  * (float)((float)(v48 * v78) - (float)(v32.m128_f32[0] * v79))))
                  + (float)(v67 * v67);
  if ( v68.m128_f32[0] == 0.0 )
    v69 = 0.0;
  else
    v69 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v68));
  v70 = v67 * v69;
  v71 = (float)((float)(v48 * v79) + (float)(v47 * v80)) + (float)(v32.m128_f32[0] * v78);
  if ( v71 <= -1.0 )
  {
    v71 = FLOAT_N1_0;
  }
  else if ( v71 >= 1.0 )
  {
    v71 = *(float *)&FLOAT_1_0;
  }
  v72 = v66 + (float)(acosf(v71) * v70);
  v73 = *(float *)(v6 + 216) * 0.5;
  v74 = *(float *)(v6 + 192);
  v75 = 1.0 / powf(*(float *)(v6 + 156), *(float *)(v6 + 192) + 1.0);
  v76 = (float)(1.0 / powf(v73, v74)) - (float)(v75 * v73);
  if ( v76 <= 0.0 )
  {
    v76 = 0.0;
  }
  else if ( v76 >= 1.0 )
  {
    goto LABEL_75;
  }
  v16 = v76;
LABEL_75:
  *(float *)(v6 + 224) = v81 / (float)((float)(v72 * 0.15915491) * v16);
  return (Render::DynamicLightComponent *)v6;
}owf(*(float *)(v6 + 156), *(float *)(v6 + 192) + 1.0);
  v76 = (float)(1.0 / powf(v73, v74)) - (float)(v75 * v73);
  if ( v76 <= 0.0 )
  {
    v76 = 0.0;
  }
  else if ( v76 >= 1.0 )
  {
    goto LABEL_75;
  }
  v16 = v76;
LABEL_75:
  *(float *)(v6 + 224) = v81 / (float)((float)(v72 * 0.15915491) * v16);
  return (

// File Line: 114
// RVA: 0x73AA0
void __fastcall Render::DynamicLightComponent::TeleportEventHandler(Render::DynamicLightComponent *this, UFG::Event *this_event)
{
  Render::DynamicLightComponent *v2; // rdi
  UFG::TransformNodeComponent *v3; // rbx
  UFG::qVector4 v4; // xmm3
  UFG::qVector4 v5; // xmm2
  UFG::qVector4 v6; // xmm1
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm4_4

  v2 = this;
  v3 = this->m_pSimObject->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(v3);
  v4 = v3->mWorldTransform.v1;
  v5 = v3->mWorldTransform.v2;
  v6 = v3->mWorldTransform.v3;
  v2->mLight.mTransform.v0 = v3->mWorldTransform.v0;
  v2->mLight.mTransform.v1 = v4;
  v2->mLight.mTransform.v2 = v5;
  v2->mLight.mTransform.v3 = v6;
  if ( v2->mLight.mType == 5 )
  {
    v7 = (float)((float)(v2->mLight.mAreaLightNearOffset * v2->mLight.mTransform.v2.y) * 0.5)
       + v2->mLight.mTransform.v3.y;
    v8 = (float)((float)(v2->mLight.mAreaLightNearOffset * v2->mLight.mTransform.v2.z) * 0.5)
       + v2->mLight.mTransform.v3.z;
    v9 = (float)((float)(v2->mLight.mAreaLightNearOffset * v2->mLight.mTransform.v2.w) * 0.5)
       + v2->mLight.mTransform.v3.w;
    v2->mLight.mTransform.v3.x = (float)((float)(v2->mLight.mAreaLightNearOffset * v2->mLight.mTransform.v2.x) * 0.5)
                               + v2->mLight.mTransform.v3.x;
    v2->mLight.mTransform.v3.y = v7;
    v2->mLight.mTransform.v3.z = v8;
    v2->mLight.mTransform.v3.w = v9;
  }
}

