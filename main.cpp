#include <opencv2/opencv.hpp>
#include <opencv2/ximgproc/segmentation.hpp>

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    // --------------------------------------------------
    // 1. Load image
    // --------------------------------------------------
    cv::Mat image = cv::imread("image.jpg");

    if (image.empty())
    {
        std::cerr << "ERROR: Could not load image.jpg\n";
        return 1;
    }

    std::cout << "Image loaded: "
              << image.cols << " x "
              << image.rows << '\n';


    // --------------------------------------------------
    // 2. Create Selective Search object
    // --------------------------------------------------
    cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentation> ss =
        cv::ximgproc::segmentation::createSelectiveSearchSegmentation();

    ss->setBaseImage(image);


    // --------------------------------------------------
    // 3. Selective Search mode
    // --------------------------------------------------
    // Fast mode is good for testing.
    ss->switchToSelectiveSearchFast();


    // --------------------------------------------------
    // 4. Run Selective Search
    // --------------------------------------------------
    std::vector<cv::Rect> regions;

    ss->process(regions);

    std::cout << "Regions found: "
              << regions.size() << '\n';


    // --------------------------------------------------
    // 5. Draw regions
    // --------------------------------------------------
    cv::Mat result = image.clone();

    // Draw only the first 100 regions so the image
    // doesn't become completely covered.
    int numberToDraw =
        std::min(100, static_cast<int>(regions.size()));

    for (int i = 0; i < numberToDraw; ++i)
    {
        cv::rectangle(
            result,
            regions[i],
            cv::Scalar(0, 255, 0),
            2
        );
    }


    // --------------------------------------------------
    // 6. Add information to the image
    // --------------------------------------------------
    std::string text =
        "Regions: " + std::to_string(regions.size());

    cv::putText(
        result,
        text,
        cv::Point(20, 40),
        cv::FONT_HERSHEY_SIMPLEX,
        1.0,
        cv::Scalar(0, 0, 255),
        2
    );


    // --------------------------------------------------
    // 7. Save result
    // --------------------------------------------------
    if (cv::imwrite("selective_search_result.jpg", result))
    {
        std::cout << "Result saved as "
                  << "selective_search_result.jpg\n";
    }
    else
    {
        std::cerr << "ERROR: Could not save result\n";
        return 1;
    }


    // --------------------------------------------------
    // 8. Display result
    // --------------------------------------------------
    cv::imshow("Selective Search", result);

    std::cout << "Press any key in the image window to exit...\n";

    cv::waitKey(0);

    return 0;
}