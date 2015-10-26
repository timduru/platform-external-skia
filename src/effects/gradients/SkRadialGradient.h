
/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkRadialGradient_DEFINED
#define SkRadialGradient_DEFINED

#include "SkGradientShaderPriv.h"

class SkRadialGradient : public SkGradientShaderBase {
public:
    SkRadialGradient(const SkPoint& center, SkScalar radius, const Descriptor&);

    size_t contextSize() const override;

    class RadialGradientContext : public SkGradientShaderBase::GradientShaderBaseContext {
    public:
        RadialGradientContext(const SkRadialGradient&, const ContextRec&);

        void shadeSpan(int x, int y, SkPMColor dstC[], int count) override;
        void shadeSpan16(int x, int y, uint16_t dstC[], int count) override;

    private:
        typedef SkGradientShaderBase::GradientShaderBaseContext INHERITED;
    };

    virtual BitmapType asABitmap(SkBitmap* bitmap,
                                 SkMatrix* matrix,
                                 TileMode* xy) const override;
    GradientType asAGradient(GradientInfo* info) const override;
    virtual bool asFragmentProcessor(GrContext*, const SkPaint&, const SkMatrix& viewM,
                                     const SkMatrix*, GrColor*,
                                     GrFragmentProcessor**) const override;

    SK_TO_STRING_OVERRIDE()
    SK_DECLARE_PUBLIC_FLATTENABLE_DESERIALIZATION_PROCS(SkRadialGradient)

protected:
    SkRadialGradient(SkReadBuffer& buffer);
    void flatten(SkWriteBuffer& buffer) const override;
    Context* onCreateContext(const ContextRec&, void* storage) const override;

private:
    friend class SkGradientShader;
    typedef SkGradientShaderBase INHERITED;
    const SkPoint fCenter;
    const SkScalar fRadius;
};

#endif
