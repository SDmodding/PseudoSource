// File Line: 39
// RVA: 0x7B3B80
void __fastcall Scaleform::GFx::AS3::StackReader::CheckObject(Scaleform::GFx::AS3::StackReader *this, Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::StackReader *v2; // rbx
  unsigned int v3; // er8
  bool v4; // al
  Scaleform::GFx::AS3::VM::Error *v5; // rax
  Scaleform::GFx::ASStringNode *v6; // rcx
  bool v7; // zf
  Scaleform::GFx::AS3::VM::Error v8; // [rsp+28h] [rbp-20h]

  v2 = this;
  v3 = v->Flags & 0x1F;
  if ( !v3 || (v3 - 12 <= 3 || v3 == 10) && !*(_QWORD *)&v->value.VNumber )
  {
    v4 = (v3 - 12 <= 3 || v3 == 10) && !*(_QWORD *)&v->value.VNumber;
    Scaleform::GFx::AS3::VM::Error::Error(&v8, (Scaleform::GFx::AS3::VM::ErrorID)(1010 - (v4 != 0)), this->VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v2->VMRef, v5, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v6 = v8.Message.pNode;
    v7 = v8.Message.pNode->RefCount == 1;
    --v6->RefCount;
    if ( v7 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  }
}

