#include <iostream>
#include <string>

using namespace std;
class ReportData {
private:
    string m_data;

public:
    ReportData(string data = "") : m_data(data) {
        cout << "ReportData constructed with: " << m_data << endl;
    }

    ~ReportData() {
        cout << "ReportData destroyed with: " << m_data << endl;
    }

    string getData() const {
        return m_data;
    }

    void setData(string data) {
        m_data = data;
    }
};

// -------------------
// Composite Class (Report class that contains ReportData)
// -------------------
<light>class Report { </light>
private:
    string m_title;
    ReportData m_reportBody; // Composition: Report *has-a* ReportData, and owns it

public:
    // Using initializer list to construct the member object m_reportBody
    Report(string title, string reportBodyData) : m_title(title), m_reportBody(reportBodyData) {
        cout << "Report constructed with title: " << m_title << endl;
    }

    ~Report() {
        cout << "Report destroyed with title: " << m_title << endl;
    }

    void printReport() const {
        cout << "Report Title: " << m_title << endl;
        cout << "Report Body: " << m_reportBody.getData() << endl;
    }

    void updateReportBody(string newData) {
        m_reportBody.setData(newData);
    }
};

// -------------------
// Main Function
// -------------------
int main() {
    // Example 1: Basic composition
    cout << "----- Example 1: Basic Composition -----" << endl;
    {
        Report annualReport("Annual Financial Report", "Revenue increased by 15%...");
        annualReport.printReport();
    } // 'annualReport' goes out of scope here; ReportData is destroyed before Report
    cout << endl;

    // Example 2: Modifying composed object
    cout << "----- Example 2: Modifying Composed Object -----" << endl;
    {
        Report projectReport("Project Status Report", "Project is on schedule...");
        projectReport.printReport();

        projectReport.updateReportBody("Project delayed due to resource constraints.");
        projectReport.printReport();
    }
    cout << endl;

    // Example 3: Demonstrating Initialization Order
    cout << "----- Example 3: Demonstrating Initialization Order -----" << endl;
    {
        Report dailyReport("Daily Activity Report", "All tasks completed successfully.");
    }
    cout << endl;

    return 0;
