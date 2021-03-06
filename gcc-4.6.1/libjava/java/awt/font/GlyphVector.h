
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_awt_font_GlyphVector__
#define __java_awt_font_GlyphVector__

#pragma interface

#include <java/lang/Object.h>
#include <gcj/array.h>

extern "Java"
{
  namespace java
  {
    namespace awt
    {
        class Font;
        class Rectangle;
        class Shape;
      namespace font
      {
          class FontRenderContext;
          class GlyphJustificationInfo;
          class GlyphMetrics;
          class GlyphVector;
      }
      namespace geom
      {
          class AffineTransform;
          class Point2D;
          class Rectangle2D;
      }
    }
  }
}

class java::awt::font::GlyphVector : public ::java::lang::Object
{

public:
  GlyphVector();
  virtual jboolean equals(::java::awt::font::GlyphVector *) = 0;
  virtual ::java::awt::Font * getFont() = 0;
  virtual ::java::awt::font::FontRenderContext * getFontRenderContext() = 0;
  virtual jint getGlyphCharIndex(jint);
  virtual JArray< jint > * getGlyphCharIndices(jint, jint, JArray< jint > *);
  virtual jint getGlyphCode(jint) = 0;
  virtual JArray< jint > * getGlyphCodes(jint, jint, JArray< jint > *) = 0;
  virtual ::java::awt::font::GlyphJustificationInfo * getGlyphJustificationInfo(jint) = 0;
  virtual ::java::awt::Shape * getGlyphLogicalBounds(jint) = 0;
  virtual ::java::awt::font::GlyphMetrics * getGlyphMetrics(jint) = 0;
  virtual ::java::awt::Shape * getGlyphOutline(jint) = 0;
  virtual ::java::awt::Shape * getGlyphOutline(jint, jfloat, jfloat);
  virtual ::java::awt::Rectangle * getGlyphPixelBounds(jint, ::java::awt::font::FontRenderContext *, jfloat, jfloat);
  virtual ::java::awt::geom::Point2D * getGlyphPosition(jint) = 0;
  virtual JArray< jfloat > * getGlyphPositions(jint, jint, JArray< jfloat > *) = 0;
  virtual ::java::awt::geom::AffineTransform * getGlyphTransform(jint) = 0;
  virtual ::java::awt::Shape * getGlyphVisualBounds(jint) = 0;
  virtual jint getLayoutFlags();
  virtual ::java::awt::geom::Rectangle2D * getLogicalBounds() = 0;
  virtual jint getNumGlyphs() = 0;
  virtual ::java::awt::Shape * getOutline() = 0;
  virtual ::java::awt::Shape * getOutline(jfloat, jfloat) = 0;
  virtual ::java::awt::Rectangle * getPixelBounds(::java::awt::font::FontRenderContext *, jfloat, jfloat);
  virtual ::java::awt::geom::Rectangle2D * getVisualBounds() = 0;
  virtual void performDefaultLayout() = 0;
  virtual void setGlyphPosition(jint, ::java::awt::geom::Point2D *) = 0;
  virtual void setGlyphTransform(jint, ::java::awt::geom::AffineTransform *) = 0;
  static const jint FLAG_COMPLEX_GLYPHS = 8;
  static const jint FLAG_HAS_POSITION_ADJUSTMENTS = 2;
  static const jint FLAG_HAS_TRANSFORMS = 1;
  static const jint FLAG_MASK = 15;
  static const jint FLAG_RUN_RTL = 4;
  static ::java::lang::Class class$;
};

#endif // __java_awt_font_GlyphVector__
