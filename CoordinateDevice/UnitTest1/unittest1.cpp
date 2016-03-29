#include "CppUnitTest.h"
#include "ModelController.h"
#include "../ICoordinate/CoordinateAxis.h"
#include "LinePrimitives.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace coordinatedevice_coordinate_coordinate;
namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// TODO:  �ڴ�������Դ���
			osg::ref_ptr<osg::Group> root = new osg::Group;
			osgViewer::Viewer view;

			auto manip = new osgGA::MultiTouchTrackballManipulator();
			view.setCameraManipulator(manip);
			//osg::ref_ptr<osg::Geode> textGeode = new osg::Geode;
			osg::ref_ptr<osg::Camera> camera = createHUDCamera(0, 1920, 0, 1080);
			//CoordinateAxis *axis = new CoordinateAxis(manip);
			CoordinateAxis *axis = new CoordinateAxis(manip);
			//osg::ref_ptr<osg::MatrixTransform>tran = axis->getAxis(-110.0f, -110.0f, 80.0f);
			axis->setRadius(380);
			axis->setOriginPoint(400, 400);
			//axis->setLabelVisibility(CoordinateNames::X_AXIS,false);
			//axis->setColor(COORDINATE_NAME::X_AXIS, 0, 0, 0);
			//axis->setAxisWidth(10);
			osg::ref_ptr<osg::MatrixTransform>tran = axis->getNode();
			camera->addChild(tran);
			//osg::MatrixTransform* tra = new osg::MatrixTransform();
			//LinePrimitives* line = new LinePrimitives();
			//line->setStartPosition(20, 20, 0);
			//line->setEndPosition(40, 40, 0);
			////tra->setMatrix(osg::Matrix::translate(osg::Vec3(20, 20, -100)));
			//tra->addChild(line->getGeometry());
			//camera->addChild(tra);

			//osg::ref_ptr<osgText::Text>text = new osgText::Text;
			//osg::ref_ptr<osgText::Font> g_font = osgText::readFontFile("fonts/arial.ttf");
			//text->setFont(g_font.get());
			//text->setCharacterSize(20.0f);
			//text->setAxisAlignment(osgText::TextBase::XY_PLANE);
			//text->setDataVariance(osg::Object::DYNAMIC);
			//text->setPosition(osg::Vec3(750.0f, 700.0f, 0.0f));
			camera->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
			//osg::ref_ptr<ModelController> ctrler = new ModelController(tran.get(), axis, text);
			//textGeode->addDrawable(text);
			//camera->addChild(textGeode);
			//view.addEventHandler(ctrler.get());
			root->addChild(camera);
			view.setSceneData(root.get());
			view.run();
		}

	};
}