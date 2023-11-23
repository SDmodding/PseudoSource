// File Line: 20
// RVA: 0x7080
void __fastcall Render::RenderPassCollector::RenderPassCollector(Render::RenderPassCollector *this)
{
  __int64 v2; // rbx
  int v3; // edx
  unsigned int *p_capacity; // rax

  v2 = 4i64;
  `eh vector constructor iterator(
    this,
    0x20ui64,
    4,
    (void (__fastcall *)(void *))Render::RenderPassComponents::RenderPassComponents);
  v3 = 0;
  p_capacity = &this->mRenderPass[0].mCompositeDrawableComponents.capacity;
  do
  {
    if ( p_capacity != (unsigned int *)20 )
    {
      *(_QWORD *)(p_capacity - 3) = 0i64;
      *(p_capacity - 5) = 0;
      *(p_capacity - 4) = 0;
      *(_QWORD *)(p_capacity + 1) = 0i64;
      *(_QWORD *)(p_capacity - 1) = 0i64;
    }
    ++v3;
    p_capacity += 8;
    --v2;
  }
  while ( v2 );
}

// File Line: 33
// RVA: 0x71A0
void __fastcall Render::AddComponent(
        Render::RenderPassComponents *render_pass,
        UFG::CompositeDrawableComponent *component)
{
  __int64 size; // rsi
  UFG::qArray<UFG::CompositeDrawableComponent *,32> *p_mCompositeDrawableComponents; // rbx
  unsigned int v5; // edi
  UFG::CompositeDrawableComponent **p; // rax

  size = render_pass->mCompositeDrawableComponents.size;
  p_mCompositeDrawableComponents = &render_pass->mCompositeDrawableComponents;
  v5 = size + 1;
  if ( (unsigned int)(size + 1) > render_pass->mCompositeDrawableComponents.capacity )
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
      (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&render_pass->mCompositeDrawableComponents,
      32 * ((v5 >> 5) + ((((_BYTE)size + 1) & 0x1F) != 0)),
      "qArray.Add");
  p = p_mCompositeDrawableComponents->p;
  p_mCompositeDrawableComponents->size = v5;
  p[size] = component;
}

// File Line: 40
// RVA: 0x7210
void __fastcall Render::RenderPassSystem::DrawRenderPass(
        Render::RenderPassCollector *render_pass_collector,
        Render::View *view,
        Illusion::eRenderPass::Enum render_pass)
{
  __int64 v3; // rsi
  __int64 v4; // rbx
  unsigned int i; // ebp

  v3 = 0i64;
  v4 = render_pass;
  view->mSubmitContext->mRenderPass = render_pass;
  for ( i = 0; i < render_pass_collector->mRenderPass[v4].mSimpleDrawableComponent.size; ++i )
    Render::SimpleDrawableComponent::Draw(render_pass_collector->mRenderPass[v4].mSimpleDrawableComponent.p[i], view);
  if ( render_pass_collector->mRenderPass[v4].mCompositeDrawableComponents.size )
  {
    do
    {
      UFG::CompositeDrawableComponent::Draw(
        render_pass_collector->mRenderPass[v4].mCompositeDrawableComponents.p[v3],
        view);
      v3 = (unsigned int)(v3 + 1);
    }
    while ( (unsigned int)v3 < render_pass_collector->mRenderPass[v4].mCompositeDrawableComponents.size );
  }
}

// File Line: 55
// RVA: 0x6E60
void __fastcall Render::RenderPassSystem::RegisterModel<UFG::CompositeDrawableComponent>(
        Render::RenderPassCollector *render_pass_collector,
        UFG::CompositeDrawableComponent *component,
        Illusion::rModel *model,
        bool *registered_passes,
        Illusion::eRenderPass::Enum *render_pass,
        int num_render_passes)
{
  unsigned int v6; // eax
  Render::RenderPassCollector *v7; // r10
  int v8; // ecx
  __int64 v9; // r13
  Illusion::eRenderPass::Enum *v10; // r14
  __int64 v11; // r12
  __int64 v12; // rcx
  UFG::qReflectObject *mData; // rdx
  __int64 v14; // rbx
  __int64 size; // r15
  unsigned int v16; // ebp
  unsigned int v17; // edi
  unsigned __int64 v18; // rax
  char *v19; // rax
  char *v20; // rsi
  __int64 i; // r9
  __int64 v22; // r8
  UFG::CompositeDrawableComponent **p; // rax
  unsigned int v24; // [rsp+20h] [rbp-58h]
  Illusion::rModel *v27; // [rsp+90h] [rbp+18h]
  bool *v28; // [rsp+98h] [rbp+20h]

  v28 = registered_passes;
  v27 = model;
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
          v12 = *(int *)v10;
          if ( !registered_passes[v12] )
          {
            mData = model->mMeshes.mData.mItems[v9].mMaterial.mData;
            if ( (_DWORD)v12 == -1
              || *((_BYTE *)&mData[2].mBaseNode.mParent + 72 * v12)
              && mData[1].mBaseNode.mChildren[0]->mChildren[4 * v12] )
            {
              v14 = v12;
              size = v7->mRenderPass[v12].mCompositeDrawableComponents.size;
              v16 = size + 1;
              if ( (unsigned int)(size + 1) > v7->mRenderPass[v12].mCompositeDrawableComponents.capacity )
              {
                v17 = 32 * ((v16 >> 5) + ((v16 & 0x1F) != 0));
                if ( v17 != (_DWORD)size )
                {
                  v18 = 8i64 * v17;
                  if ( !is_mul_ok(v17, 8ui64) )
                    v18 = -1i64;
                  v19 = UFG::qMalloc(v18, "qArray.Add", 0i64);
                  v7 = render_pass_collector;
                  v20 = v19;
                  if ( render_pass_collector->mRenderPass[v14].mCompositeDrawableComponents.p )
                  {
                    for ( i = 0i64;
                          (unsigned int)i < render_pass_collector->mRenderPass[v14].mCompositeDrawableComponents.size;
                          *(_QWORD *)&v19[v22 * 8] = render_pass_collector->mRenderPass[v14].mCompositeDrawableComponents.p[v22] )
                    {
                      v22 = i;
                      i = (unsigned int)(i + 1);
                    }
                    operator delete[](render_pass_collector->mRenderPass[v14].mCompositeDrawableComponents.p);
                    v7 = render_pass_collector;
                  }
                  registered_passes = v28;
                  model = v27;
                  v7->mRenderPass[v14].mCompositeDrawableComponents.p = (UFG::CompositeDrawableComponent **)v20;
                  v7->mRenderPass[v14].mCompositeDrawableComponents.capacity = v17;
                }
              }
              p = v7->mRenderPass[v14].mCompositeDrawableComponents.p;
              v7->mRenderPass[v14].mCompositeDrawableComponents.size = v16;
              p[size] = component;
              registered_passes[*(int *)v10] = 1;
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
void __fastcall Render::RenderPassSystem::RegisterComponent(
        Render::RenderPassCollector *render_pass_collector,
        Render::SimpleDrawableComponent *component,
        float pixel_coverage,
        float distance,
        Illusion::eRenderPass::Enum *render_pass,
        int num_render_passes)
{
  Render::SimpleDrawableComponent *v6; // rbx
  Render::RenderPassCollector *v7; // rdi
  unsigned int v8; // ebp
  int v9; // esi
  Illusion::rModel *v10; // rdx
  unsigned int v11; // eax
  __int64 v12; // r13
  Illusion::eRenderPass::Enum *v13; // r14
  __int64 v14; // r12
  __int64 v15; // rcx
  UFG::qReflectObject *mData; // rdx
  Render::RenderPassComponents *v17; // rbx
  __int64 size; // r15
  unsigned int v19; // ebp
  unsigned int v20; // edi
  unsigned __int64 v21; // rax
  char *v22; // rax
  char *v23; // rsi
  __int64 i; // r9
  __int64 v25; // r8
  Render::SimpleDrawableComponent **p; // rax
  char dest[4]; // [rsp+20h] [rbp-58h] BYREF
  unsigned int v28; // [rsp+24h] [rbp-54h]
  unsigned int v29; // [rsp+28h] [rbp-50h]
  Illusion::rModel *v30; // [rsp+30h] [rbp-48h]

  v6 = component;
  v7 = render_pass_collector;
  UFG::qMemSet(dest, 0, 4u);
  v8 = 0;
  v29 = 0;
  if ( !UFG::UIHKPlayerObjective::GetObjective(v6)->mModels.mData.mNumItems )
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
          v15 = *(int *)v13;
          if ( !dest[v15] )
          {
            mData = v10->mMeshes.mData.mItems[v12].mMaterial.mData;
            if ( (_DWORD)v15 == -1
              || *((_BYTE *)&mData[2].mBaseNode.mParent + 72 * v15)
              && mData[1].mBaseNode.mChildren[0]->mChildren[4 * v15] )
            {
              v17 = &v7->mRenderPass[*(int *)v13];
              size = v17->mSimpleDrawableComponent.size;
              v19 = size + 1;
              if ( (unsigned int)(size + 1) > v17->mSimpleDrawableComponent.capacity )
              {
                v20 = 32 * ((v19 >> 5) + ((v19 & 0x1F) != 0));
                if ( v20 != (_DWORD)size )
                {
                  v21 = 8i64 * v20;
                  if ( !is_mul_ok(v20, 8ui64) )
                    v21 = -1i64;
                  v22 = UFG::qMalloc(v21, "qArray.Add", 0i64);
                  v23 = v22;
                  if ( v17->mSimpleDrawableComponent.p )
                  {
                    for ( i = 0i64;
                          (unsigned int)i < v17->mSimpleDrawableComponent.size;
                          *(_QWORD *)&v22[v25 * 8] = v17->mSimpleDrawableComponent.p[v25] )
                    {
                      v25 = i;
                      i = (unsigned int)(i + 1);
                    }
                    operator delete[](v17->mSimpleDrawableComponent.p);
                  }
                  v17->mSimpleDrawableComponent.p = (Render::SimpleDrawableComponent **)v23;
                  v17->mSimpleDrawableComponent.capacity = v20;
                }
                v7 = render_pass_collector;
              }
              p = v17->mSimpleDrawableComponent.p;
              v10 = v30;
              v17->mSimpleDrawableComponent.size = v19;
              v6 = component;
              p[size] = component;
              dest[*(int *)v13] = 1;
              goto LABEL_24;
            }
            v10 = v30;
          }
          v6 = component;
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
}9;
LABEL_28:
    v29 = ++v8;
  }
  whi

// File Line: 86
// RVA: 0x72B0
void __fastcall Render::RenderPassSystem::RegisterComponent(
        Render::RenderPassCollector *render_pass_collector,
        UFG::CompositeDrawableComponent *component,
        float pixel_coverage,
        float distance,
        Illusion::eRenderPass::Enum *render_pass,
        int num_render_passes)
{
  ModelType *v8; // rbp
  UFG::qList<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin,1,0> *mNext; // rax
  int v10; // r15d
  Illusion::eRenderPass::Enum *v11; // r12
  Illusion::rModel *v12; // r8
  ModelType *v13; // rdi
  UFG::qList<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid,1,0> *v14; // rax
  UFG::qList<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid,1,0> *p_mModelBindingRigidTable; // r13
  Illusion::rModel *v16; // r8
  UFG::qList<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid,1,0> *v17; // r12
  __int64 size; // r15
  unsigned int v19; // ebp
  unsigned int v20; // edi
  unsigned __int64 v21; // rax
  char *v22; // rax
  UFG::CompositeDrawableComponent **v23; // rsi
  __int64 i; // r9
  UFG::CompositeDrawableComponent **p; // rax
  char dest; // [rsp+68h] [rbp+10h] BYREF

  v8 = component->mModelType[(unsigned int)UFG::CompositeDrawableComponent::GetLOD(component, pixel_coverage)];
  UFG::qMemSet(&dest, 0, 4u);
  mNext = (UFG::qList<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin,1,0> *)v8->mModelBindingSkinTable.mNode.mNext;
  if ( mNext != &v8->mModelBindingSkinTable )
  {
    v10 = num_render_passes;
    v11 = render_pass;
    do
    {
      v12 = (Illusion::rModel *)mNext[4].mNode.mNext;
      v13 = (ModelType *)mNext->mNode.mNext;
      if ( v12 )
      {
        Render::RenderPassSystem::RegisterModel<UFG::CompositeDrawableComponent>(
          render_pass_collector,
          component,
          v12,
          (bool *)&dest,
          v11,
          v10);
      }
      else if ( mNext[3].mNode.mNext && !dest )
      {
        Render::AddComponent(render_pass_collector->mRenderPass, component);
        dest = 1;
      }
      mNext = (UFG::qList<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin,1,0> *)v13;
    }
    while ( v13 != (ModelType *)&v8->mModelBindingSkinTable );
  }
  v14 = (UFG::qList<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid,1,0> *)v8->mModelBindingRigidTable.mNode.mNext;
  p_mModelBindingRigidTable = &v8->mModelBindingRigidTable;
  if ( v14 != &v8->mModelBindingRigidTable )
  {
    do
    {
      v16 = (Illusion::rModel *)v14[3].mNode.mNext;
      v17 = (UFG::qList<ModelType::ModelBindingRigid,ModelType::ModelBindingRigid,1,0> *)v14->mNode.mNext;
      if ( v16 )
      {
        Render::RenderPassSystem::RegisterModel<UFG::CompositeDrawableComponent>(
          render_pass_collector,
          component,
          v16,
          (bool *)&dest,
          render_pass,
          num_render_passes);
      }
      else if ( v14[2].mNode.mNext && !dest )
      {
        size = render_pass_collector->mRenderPass[0].mCompositeDrawableComponents.size;
        v19 = size + 1;
        if ( (unsigned int)(size + 1) > render_pass_collector->mRenderPass[0].mCompositeDrawableComponents.capacity )
        {
          v20 = 32 * ((v19 >> 5) + ((v19 & 0x1F) != 0));
          if ( v20 != (_DWORD)size )
          {
            v21 = 8i64 * v20;
            if ( !is_mul_ok(v20, 8ui64) )
              v21 = -1i64;
            v22 = UFG::qMalloc(v21, "qArray.Add", 0i64);
            v23 = (UFG::CompositeDrawableComponent **)v22;
            if ( render_pass_collector->mRenderPass[0].mCompositeDrawableComponents.p )
            {
              for ( i = 0i64;
                    (unsigned int)i < render_pass_collector->mRenderPass[0].mCompositeDrawableComponents.size;
                    i = (unsigned int)(i + 1) )
              {
                *(_QWORD *)&v22[8 * i] = render_pass_collector->mRenderPass[0].mCompositeDrawableComponents.p[i];
              }
              operator delete[](render_pass_collector->mRenderPass[0].mCompositeDrawableComponents.p);
            }
            render_pass_collector->mRenderPass[0].mCompositeDrawableComponents.p = v23;
            render_pass_collector->mRenderPass[0].mCompositeDrawableComponents.capacity = v20;
          }
        }
        p = render_pass_collector->mRenderPass[0].mCompositeDrawableComponents.p;
        render_pass_collector->mRenderPass[0].mCompositeDrawableComponents.size = v19;
        p[size] = component;
        dest = 1;
      }
      v14 = v17;
    }
    while ( v17 != p_mModelBindingRigidTable );
  }
}

