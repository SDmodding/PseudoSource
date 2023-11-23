// File Line: 39
// RVA: 0x7B3B80
void __fastcall Scaleform::GFx::AS3::StackReader::CheckObject(
        Scaleform::GFx::AS3::StackReader *this,
        Scaleform::GFx::AS3::Value *v)
{
  unsigned int v3; // r8d
  bool v4; // al
  Scaleform::GFx::AS3::VM::Error *v5; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v8; // [rsp+28h] [rbp-20h] BYREF

  v3 = v->Flags & 0x1F;
  if ( !v3 || (v3 - 12 <= 3 || v3 == 10) && !v->value.VS._1.VStr )
  {
    v4 = (v3 - 12 <= 3 || v3 == 10) && !v->value.VS._1.VStr;
    Scaleform::GFx::AS3::VM::Error::Error(&v8, 1010 - v4, this->VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(this->VMRef, v5, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    pNode = v8.Message.pNode;
    if ( v8.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

