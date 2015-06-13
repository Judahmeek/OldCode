/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package traveltrail.rows;

import java.sql.ResultSet;
import java.sql.SQLException;

/**
 *
 * @author Wap
 */
public final class LocationRow implements Extractable{
    private int id;
    private String name;
    private String description;
    private String[] links;
    private String[] insideLinks;
    private String[] people;
    
    @Override
    public Extractable extractRow(ResultSet resultSet) throws SQLException {
        return new LocationRow(resultSet.getInt(1), resultSet.getString(2), resultSet.getString(3), resultSet.getString(4), resultSet.getString(5), resultSet.getString(6));
    }
    
    /**
     *
     */
    public LocationRow(){
        setID(-1);
        setName(null);
        setDescription(null);
        setLinks(null);
        setInsideLinks(null);
        setPeople(null);
    }
    
    /**
     *
     * @param id
     * @param name
     * @param description
     * @param links
     * @param insideLinks
     * @param people
     */
    public LocationRow(int id, String name, String description, String links, String insideLinks, String people){
        setID(id);
        setName(name);
        setDescription(description);
        setLinks(links);
        setInsideLinks(insideLinks);
        setPeople(people);        
    }

    /**
     *
     * @return
     */
    public int getID() {
        return id;
    }

    /**
     *
     * @param id
     */
    public void setID(int id) {
        this.id = id;
    }

    /**
     *
     * @return
     */
    public String getName() {
        return name;
    }

    /**
     *
     * @param name
     */
    public void setName(String name) {
        this.name = name;
    }

    /**
     *
     * @return
     */
    public String[] getLinks() {
        return links;
    }

    /**
     *
     * @param links
     */
    public void setLinks(String links) {
        this.links = links.split(";");
    }

    /**
     *
     * @return
     */
    public String[] getInsideLinks() {
        return insideLinks;
    }

    /**
     *
     * @param insideLinks
     */
    public void setInsideLinks(String insideLinks) {
        this.insideLinks = insideLinks.split(";");
    }

    /**
     *
     * @return
     */
    public String[] getPeople() {
        return people;
    }

    /**
     *
     * @param people
     */
    public void setPeople(String people) {
        this.people = people.split(";");
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

}
