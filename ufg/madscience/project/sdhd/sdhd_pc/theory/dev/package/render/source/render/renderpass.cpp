// File Line: 20
// RVA: 0x7080
void __fastcall Render::RenderPassCollector::RenderPassCollector(Render::RenderPassCollector *this)
{
  Render::RenderPassCollector *v1; // rdi
  signed __int64 v2; // rbx
  int v3; // edx
  signed __int64 v4; // rax

  v1 = this;
  v2 = 4i64;
  `eh vector constructor iterator(
    this,
    0x20ui64,
    4,
    (void (__fastcall *)(void *))Render::RenderPassComponents::RenderPassComponents);
  v3 = 0;
  v4 = (signed __int64)&v1->mRenderPass[0].mCompositeDrawableComponents.capacity;
  do
  {
    if ( v4 != 20 )
    {
      *(_QWORD *)(v4 - 12) = 0i64;
      *(_DWORD *)(v4 - 20) = 0;
      *(_DWORD *)(v4 - 16) = 0;
      *(_QWORD *)(v4 + 4) = 0i64;
      *(_QWORD *)(v4 - 4) = 0i64;
    }
    ++v3;
    v4 += 32i64;
    --v2;
  }
  while ( v2 );
}

// File Line: 33
// RVA: 0x71A0
void __fastcall Render::AddComponent(Render::RenderPassComponents *render_pass, UFG::CompositeDrawableComponent *component)
{
  __int64 v2; // rsi
  UFG::qArray<UFG::CompositeDrawableComponent *,32> *v3; // rbx
  UFG::CompositeDrawableComponent *v4; // rbp
  unsigned int v5; // edi
  UFG::CompositeDrawableComponent **v6; // rax

  v2 = render_pass->mCompositeDrawableComponents.size;
  v3 = &render_pass->mCompositeDrawableComponents;
  v4 = component;
  v5 = v2 + 1;
  if ( (unsigned int)(v2 + 1) > render_pass->mCompositeDrawableComponents.capacity )
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
      (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&render_pass->mCompositeDrawableComponents,
      32 * ((v5 >> 5) + ((((_BYTE)v2 + 1) & 0x1F) != 0)),
      "qArray.Add");
  v6 = v3->p;
  v3->size = v5;
  v6[v2] = v4;
}

// File Line: 40
// RVA: 0x7210
void __fastcall Render::RenderPassSystem::DrawRenderPass(Render::RenderPassCollector *render_pass_collector, Render::View *view, Illusion::eRenderPass::Enum render_pass)
{
  __int64 v3; // rsi
  unsigned __int64 v4; // rbx
  Render::View *v5; // r14
  Render::RenderPassCollector *v6; // rdi
  unsigned int v7; // ebp

  v3 = 0i64;
  v4 = (signed int)render_pass;
  view->mSubmitContext->mRenderPass = render_pass;
  v5 = view;
  v6 = render_pass_collector;
  v7 = 0;
  if ( render_pass_collector->mRenderPass[v4].mSimpleDrawableComponent.size )
  {
    do
      Render::SimpleDrawableComponent::Draw(v6->mRenderPass[v4].mSimpleDrawableComponent.p[v7++], v5);
    while ( v7 < v6->mRenderPass[v4].mSimpleDrawableComponent.size );
  }
  if ( v6->mRenderPass[v4].mCompositeDrawableComponents.size > 0 )
  {
    do
    {
      UFG::CompositeDrawableComponent::Draw(v6->mRenderPass[v4].mCompositeDrawableComponents.p[v3], v5);
      v3 = (unsigned int)(v3 + 1);
    }
    while ( (unsigned int)v3 < v6->mRenderPass[v4].mCompositeDrawableComponents.size );
  }
}

// File Line: 55
// RVA: 0x6E60
void __fastcall Render::RenderPassSystem::RegisterModel<UFG::CompositeDrawableComponent>(Render::RenderPassCollector *render_pass_collector, UFG::CompositeDrawableComponent *component, Illusion::rModel *model, bool *registered_passes, Illusion::eRenderPass::Enum *render_pass, int num_render_passes)
{
  unsigned int v6; // eax
  Render::RenderPassCollector *v7; // r10
  int v8; // ecx
  __int64 v9; // r13
  Illusion::eRenderPass::Enum *v10; // r14
  __int64 v11; // r12
  signed __int64 v12; // rcx
  UFG::qReflectObject *v13; // rdx
  signed __int64 v14; // rbx
  __int64 v15; // r15
  unsigned int v16; // ebp
  unsigned int v17; // edi
  unsigned __int64 v18; // rax
  char *v19; // rax
  char *v20; // rsi
  signed __int64 v21; // r9
  signed __int64 v22; // r8
  UFG::CompositeDrawableComponent **v23; // rax
  unsigned int v24; // [rsp+20h] [rbp-58h]
  Render::RenderPassCollector *v25; // [rsp+80h] [rbp+8h]
  UFG::CompositeDrawableComponent *v26; // [rsp+88h] [rbp+10h]
  Illusion::rModel *v27; // [rsp+90h] [rbp+18h]
  bool *v28; // [rsp+98h] [rbp+20h]

  v28 = registered_passes;
  v27 = model;
  v26 = component;
  v25 = render_pass_collector;
  v6 = 0;
  v7 = render_pass_collector;
  v24 = 0;
  if ( model->mMeshes.mData.mNumItems )
  {
    v8 = num_render_passes;
    do
    {
      v9 = v6;
      if ( model->mMeshes.mData.mItems[v9].mMaterial.mData && v8 > 0 )
      {
        v10 = render_pass;
        v11 = (unsigned int)v8;
        do
        {
          v12 = *(signed int *)v10;
          if ( !registered_passes[v12] )
          {
            v13 = model->mMeshes.mData.mItems[v9].mMaterial.mData;
            if ( (_DWORD)v12 == -1
              || *((_BYTE *)&v13[2].mBaseNode.mParent + 72 * v12) && v13[1].mBaseNode.mChildren[0]->mChildren[4 * v12] )
            {
              v14 = v12;
              v15 = v7->mRenderPass[v12].mCompositeDrawableComponents.size;
              v16 = v15 + 1;
              if ( (unsigned int)(v15 + 1) > v7->mRenderPass[v12].mCompositeDrawableComponents.capacity )
              {
                v17 = 32 * ((v16 >> 5) + ((v16 & 0x1F) != 0));
                if ( v17 != (_DWORD)v15 )
                {
                  v18 = 8i64 * v17;
                  if ( !is_mul_ok(v17, 8ui64) )
                    v18 = -1i64;
                  v19 = UFG::qMalloc(v18, "qArray.Add", 0i64);
                  v7 = v25;
                  v20 = v19;
                  if ( v25->mRenderPass[v14].mCompositeDrawableComponents.p )
                  {
                    v21 = 0i64;
                    if ( v25->mRenderPass[v14].mCompositeDrawableComponents.size )
                    {
                      do
                      {
                        v22 = v21;
                        v21 = (unsigned int)(v21 + 1);
                        *(_QWORD *)&v19[v22 * 8] = v25->mRenderPass[v14].mCompositeDrawableComponents.p[v22];
                      }
                      while ( (unsigned int)v21 < v25->mRenderPass[v14].mCompositeDrawableComponents.size );
                    }
                    operator delete[](v25->mRenderPass[v14].mCompositeDrawableComponents.p);
                    v7 = v25;
                  }
                  registered_passes = v28;
                  model = v27;
                  v7->mRenderPass[v14].mCompositeDrawableComponents.p = (UFG::CompositeDrawableComponent **)v20;
                  v7->mRenderPass[v14].mCompositeDrawableComponents.capacity = v17;
                }
              }
              v23 = v7->mRenderPass[v14].mCompositeDrawableComponents.p;
              v7->mRenderPass[v14].mCompositeDrawableComponents.size = v16;
              v23[v15] = v26;
              registered_passes[*(signed int *)v10] = 1;
            }
          }
          ++v10;
          --v11;
        }
        while ( v11 );
        v8 = num_render_passes;
      }
      v6 = v24 + 1;
      v24 = v6;
    }
    while ( v6 < model->mMeshes.mData.mNumItems );
  }
}

// File Line: 75
// RVA: 0x74C0
void __fastcall Render::RenderPassSystem::RegisterComponent(Render::RenderPassCollector *render_pass_collector, Render::SimpleDrawableComponent *component, float pixel_coverage, float distance, Illusion::eRenderPass::Enum *render_pass, int num_render_passes)
{
  Render::SimpleDrawableComponent *v6; // rbx
  Render::RenderPassCollector *v7; // rdi
  unsigned int v8; // ebp
  int v9; // esi
  Illusion::rModel *v10; // rdx
  unsigned int v11; // eax
  signed __int64 v12; // r13
  Illusion::eRenderPass::Enum *v13; // r14
  __int64 v14; // r12
  __int64 v15; // rcx
  UFG::qReflectObject *v16; // rdx
  Render::RenderPassComponents *v17; // rbx
  __int64 v18; // r15
  unsigned int v19; // ebp
  unsigned int v20; // edi
  unsigned __int64 v21; // rax
  char *v22; // rax
  char *v23; // rsi
  signed __int64 v24; // r9
  signed __int64 v25; // r8
  Render::SimpleDrawableComponent **v26; // rax
  char dest[4]; // [rsp+20h] [rbp-58h]
  unsigned int v28; // [rsp+24h] [rbp-54h]
  unsigned int v29; // [rsp+28h] [rbp-50h]
  Illusion::rModel *v30; // [rsp+30h] [rbp-48h]
  Render::RenderPassCollector *v31; // [rsp+80h] [rbp+8h]
  Render::SimpleDrawableComponent *v32; // [rsp+88h] [rbp+10h]

  v32 = component;
  v31 = render_pass_collector;
  v6 = component;
  v7 = render_pass_collector;
  UFG::qMemSet(dest, 0, 4u);
  v8 = 0;
  v29 = 0;
  if ( UFG::UIHKPlayerObjective::GetObjective(v6)->mModels.mData.mNumItems <= 0 )
    return;
  v9 = num_render_passes;
  do
  {
    v10 = &UFG::UIHKPlayerObjective::GetObjective(v6)->mModels.mData.mItems[v8];
    v11 = 0;
    v30 = v10;
    v28 = 0;
    if ( !v10->mMeshes.mData.mNumItems )
      goto LABEL_28;
    do
    {
      v12 = v11;
      if ( v10->mMeshes.mData.mItems[v12].mMaterial.mData && v9 > 0 )
      {
        v13 = render_pass;
        v14 = (unsigned int)v9;
        while ( 1 )
        {
          v15 = *(signed int *)v13;
          if ( !dest[v15] )
          {
            v16 = v10->mMeshes.mData.mItems[v12].mMaterial.mData;
            if ( (_DWORD)v15 == -1
              || *((_BYTE *)&v16[2].mBaseNode.mParent + 72 * v15) && v16[1].mBaseNode.mChildren[0]->mChildren[4 * v15] )
            {
              v17 = &v7->mRenderPass[*(signed int *)v13];
              v18 = v17->mSimpleDrawableComponent.size;
              v19 = v18 + 1;
              if ( (unsigned int)(v18 + 1) > v17->mSimpleDrawableComponent.capacity )
              {
                v20 = 32 * ((v19 >> 5) + ((v19 & 0x1F) != 0));
                if ( v20 != (_DWORD)v18 )
                {
                  v21 = 8i64 * v20;
                  if ( !is_mul_ok(v20, 8ui64) )
                    v21 = -1i64;
                  v22 = UFG::qMalloc(v21, "qArray.Add", 0i64);
                  v23 = v22;
                  if ( v17->mSimpleDrawableComponent.p )
                  {
                    v24 = 0i64;
                    if ( v17->mSimpleDrawableComponent.size )
                    {
                      do
                      {
                        v25 = v24;
                        v24 = (unsigned int)(v24 + 1);
                        *(_QWORD *)&v22[v25 * 8] = v17->mSimpleDrawableComponent.p[v25];
                      }
                      while ( (unsigned int)v24 < v17->mSimpleDrawableComponent.size );
                    }
                    operator delete[](v17->mSimpleDrawableComponent.p);
                  }
                  v17->mSimpleDrawableComponent.p = (Render::SimpleDrawableComponent **)v23;
                  v17->mSimpleDrawableComponent.capacity = v20;
                }
                v7 = v31;
              }
              v26 = v17->mSimpleDrawableComponent.p;
              v10 = v30;
              v17->mSimpleDrawableComponent.size = v19;
              v6 = v32;
              v26[v18] = v32;
              dest[*(signed int *)v13] = 1;
              goto LABEL_24;
            }
            v10 = v30;
          }
          v6 = v32;
LABEL_24:
          ++v13;
          if ( !--v14 )
          {
            v9 = num_render_passes;
            break;
          }
        }
      }
      v11 = v28 + 1;
      v28 = v11;
    }
    while ( v11 < v10->mMeshes.mData.mNumItems );
    v8 = v29;
LABEL_28:
    v29 = ++v8;
  }
  while ( v8 < UFG::UIHKPlayerObjective::GetObjective(v6)->mModels.mData.mNumItems );
}

// File Line: 86
// RVA: 0x72B0
void __fastcall Render::RenderPassSystem::RegisterComponent(Render::RenderPassCollector *render_pass_collector, UFG::CompositeDrawableComponent *component, float pixel_coverage, float distance, Illusion::eRenderPass::Enum *render_pass, int num_render_passes)
{
  Render::RenderPassCollector *v6; // rbx
  UFG::CompositeDrawableComponent *v7; // r14
  ModelType *v8; // rbp
  UFG::qList<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin,1,0> *v9; // rax
  int v10; // er15
  Illusion::eRenderPass::Enum *v11; // r12
  Illusion::rModel *v12; // r8
  ModelType *v13; // rdi
  UFG::qList<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid,1,0> *v14; // rax
  signed __int64 v15; // r13
  Illusion::rModel *v16; // r8
  UFG::qList<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid,1,0> *v17; // r12
  __int64 v18; // r15
  unsigned int v19; // ebp
  unsigned int v20; // edi
  unsigned __int64 v21; // rax
  char *v22; // rax
  char *v23; // rsi
  __int64 v24; // r9
  UFG::CompositeDrawableComponent **v25; // rax
  char dest; // [rsp+68h] [rbp+10h]

  v6 = render_pass_collector;
  v7 = component;
  v8 = component->mModelType[(unsigned int)UFG::CompositeDrawableComponent::GetLOD(component, pixel_coverage)];
  UFG::qMemSet(&dest, 0, 4u);
  v9 = (UFG::qList<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin,1,0> *)v8->mModelBindingSkinTable.mNode.mNext;
  if ( v9 != &v8->mModelBindingSkinTable )
  {
    v10 = num_render_passes;
    v11 = render_pass;
    do
    {
      v12 = (Illusion::rModel *)v9[4].mNode.mNext;
      v13 = (ModelType *)v9->mNode.mNext;
      if ( v12 )
      {
        Render::RenderPassSystem::RegisterModel<UFG::CompositeDrawableComponent>(v6, v7, v12, (bool *)&dest, v11, v10);
      }
      else if ( v9[3].mNode.mNext && !dest )
      {
        Render::AddComponent(v6->mRenderPass, v7);
        dest = 1;
      }
      v9 = (UFG::qList<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin,1,0> *)v13;
    }
    while ( v13 != (ModelType *)&v8->mModelBindingSkinTable );
  }
  v14 = (UFG::qList<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid,1,0> *)v8->mModelBindingRigidTable.mNode.mNext;
  v15 = (signed __int64)&v8->mModelBindingRigidTable;
  if ( v14 != &v8->mModelBindingRigidTable )
  {
    do
    {
      v16 = (Illusion::rModel *)v14[3].mNode.mNext;
      v17 = (UFG::qList<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid,1,0> *)v14->mNode.mNext;
      if ( v16 )
      {
        Render::RenderPassSystem::RegisterModel<UFG::CompositeDrawableComponent>(
          v6,
          v7,
          v16,
          (bool *)&dest,
          render_pass,
          num_render_passes);
      }
      else if ( v14[2].mNode.mNext && !dest )
      {
        v18 = v6->mRenderPass[0].mCompositeDrawableComponents.size;
        v19 = v18 + 1;
        if ( (unsigned int)(v18 + 1) > v6->mRenderPass[0].mCompositeDrawableComponents.capacity )
        {
          v20 = 32 * ((v19 >> 5) + ((v19 & 0x1F) != 0));
          if ( v20 != (_DWORD)v18 )
          {
            v21 = 8i64 * v20;
            if ( !is_mul_ok(v20, 8ui64) )
              v21 = -1i64;
            v22 = UFG::qMalloc(v21, "qArray.Add", 0i64);
            v23 = v22;
            if ( v6->mRenderPass[0].mCompositeDrawableComponents.p )
            {
              v24 = 0i64;
              if ( v6->mRenderPass[0].mCompositeDrawableComponents.size )
              {
                do
                {
                  *(_QWORD *)&v22[8 * v24] = v6->mRenderPass[0].mCompositeDrawableComponents.p[v24];
                  v24 = (unsigned int)(v24 + 1);
                }
                while ( (unsigned int)v24 < v6->mRenderPass[0].mCompositeDrawableComponents.size );
              }
              operator delete[](v6->mRenderPass[0].mCompositeDrawableComponents.p);
            }
            v6->mRenderPass[0].mCompositeDrawableComponents.p = (UFG::CompositeDrawableComponent **)v23;
            v6->mRenderPass[0].mCompositeDrawableComponents.capacity = v20;
          }
        }
        v25 = v6->mRenderPass[0].mCompositeDrawableComponents.p;
        v6->mRenderPass[0].mCompositeDrawableComponents.size = v19;
        v25[v18] = v7;
        dest = 1;
      }
      v14 = v17;
    }
    while ( v17 != (UFG::qList<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid,1,0> *)v15 );
  }
}

