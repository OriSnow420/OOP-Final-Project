// TODO: file comment

#ifndef MultiPoint_hpp
#define MultiPoint_hpp

#include "Point3D.hpp"
#include <algorithm>
#include <exception>
#include <initializer_list>
#include <ostream>

template<size_t N>
class MultiPoint {
private:
    std::vector<Point3D> m_points;
    virtual void innerSet(const Point3D& newPoint, int index){
        if (index < 0 || index >= N){
            throw std::exception(
                "[MultiPoint::innerSet] Passing wrong number of arguments");
        }
        m_points[index] = newPoint;
    }

public:
    explicit MultiPoint(std::initializer_list<Point3D> Ilist):
    m_points(Ilist){
        if(Ilist.size() != N){
            throw std::exception(
                "[MultiPoint::MultiPoint] Passing wrong number of arguments");
        }
    }

    virtual ~MultiPoint() {}

    bool operator==(const MultiPoint<N>& rhs) const noexcept {
        for (const auto& point : m_points) {
            if (std::find(rhs.m_points.begin(), rhs.m_points.end(), 
            point) == rhs.m_points.end()) {
                return false;
            }
        }
        return true;
    }

    void setPoint(const Point3D& newPoint, int index) {
        innerSet(newPoint, index);
    }

    std::vector<Point3D> getPoints() const noexcept {
        return m_points;
    }

    Point3D getPoint(int index) const {
        if(index < 0 || index >= N){
            throw std::exception(
                "[MultiPoint::getPoint] Passing wrong index!");
        }
        return m_points[index];
    }

    template<size_t M>
    friend std::ostream& operator<<
    (std::ostream& out, const MultiPoint<M>& points); 

};

template<size_t M>
std::ostream& operator<<
(std::ostream& out, const MultiPoint<M>& points) {
    out << "[";
    for (int i = 0; i < points.m_points.size(); i++) {
        out << points.m_points[i];
        if (i < points.m_points.size() - 1) {
            out << ", ";
        }
    }
    out << "]";
    return out;
}

#endif
